import numpy as np
import math

counter = 0

def rand_x_generator():
	x = np.random.randint(64, size = 2)
	return x

def dec2bin(number):
	binary = []
	while True:
		if number != 0:
			digit = number % 2
			binary.append(digit)
			number = math.floor(number/2)
		else:
			break
	while True:
		if len(binary) < 6:
			binary.append(0)
		else:
			break
	binary = binary[::-1]
	return binary

def bin2dec(bin_array):
	bin_array = bin_array[::-1]
	number = 0
	for i in range(len(bin_array)):
		number += bin_array[i] * 2**i
	return number

def function(x):
	x1 = x[0]
	x2 = x[1]
	sin1 = math.sin(np.deg2rad((x1-(x2/8))**2))
	sin2 = math.sin(np.deg2rad((x2+(x1/8))**2))
	numerator = sin1 + sin2
	denominator = math.sqrt(((x1-8.6998)**2)+((x2-6.7665)**2)) + 1
	result = numerator / denominator
	return result

def flip_bit(x, dim):
	global counter
	counter = counter % 6
	bin_array = list(dec2bin(x[dim]))
	if bin_array[counter] == 0:
		bin_array[counter] = 1
	else:
		bin_array[counter] = 0
	counter += 1
	decimal = bin2dec(bin_array)
	return decimal

def simulated_annealing(x, initial_solt):		
	temp = 0.5
	scale = 0.1
	results = []
	current_solt = initial_solt
	results.append(initial_solt)
	print(x[0], x[1], initial_solt)
	while True:
		x[0] = flip_bit(x, 0)
		x[1] = flip_bit(x, 1)
		neighbor_solt = function(x)
		delta = initial_solt - neighbor_solt
		if neighbor_solt in results:
			print(results)
			print(f"Final solution is {current_solt}")
			return 0
		else:
			print(x[0], x[1], neighbor_solt)
			if delta < 0:
				if neighbor_solt > current_solt:
					current_solt = neighbor_solt
					initial_solt = neighbor_solt
					results.append(initial_solt)
					temp = temp * scale
					continue
				else:
					initial_solt = neighbor_solt
					results.append(initial_solt)
					temp = temp * scale
					continue
			elif delta > 0:
				probability = math.exp(((-delta)/temp))
				temp = temp * scale
				if probability > 0.5:
					initial_solt = neighbor_solt
					results.append(neighbor_solt)
					continue
				else:
					print(results)
					print(f"Final solution is {current_solt}")
					return 0

def main():
	x = rand_x_generator()
	initial_solt = function(x)
	simulated_annealing(x, initial_solt)

if __name__ == "__main__":
	main()