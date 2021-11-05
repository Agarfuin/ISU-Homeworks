import numpy as np
import math
from scipy.stats import binom

array = np.random.randint(2, size =(10000, 10))

ones = 0
zero_one = 0
one_one = 0
two_one = 0
three_one = 0
four_one = 0
five_one = 0
six_one = 0
seven_one = 0
eight_one = 0
nine_one = 0
ten_one = 0

for i in range(10000):
    for j in range(10):
        if array[i][j] == 1:
            ones = ones + 1
        else:
            continue
    if ones == 0:
        zero_one = zero_one + 1
        ones = 0
    elif ones == 1:
        one_one = one_one + 1
        ones = 0
    elif ones == 2:
        two_one = two_one + 1
        ones = 0
    elif ones == 3:
        three_one = three_one + 1
        ones = 0
    elif ones == 4:
        four_one = four_one + 1
        ones = 0
    elif ones == 5:
        five_one = five_one + 1
        ones = 0
    elif ones == 6:
        six_one = six_one + 1
        ones = 0
    elif ones == 7:
        seven_one = seven_one + 1
        ones = 0
    elif ones == 8:
        eight_one = eight_one + 1
        ones = 0
    elif ones == 9:
        nine_one = nine_one + 1
        ones = 0
    elif ones == 10:
        ten_one = ten_one + 1
        ones = 0
    else:
        continue

p_sim = float((zero_one + one_one + two_one + three_one + four_one)) / float(10000)

"""
print(zero_one)
print(one_one)
print(two_one)
print(three_one)
print(four_one)
print(five_one)
print(six_one)
print(seven_one)
print(eight_one)
print(nine_one)
print(ten_one)
"""

print(p_sim)

pmf_4 = binom.pmf(4, 10, 0.5, loc=0)
pmf_3 = binom.pmf(3, 10, 0.5, loc=0)
pmf_2 = binom.pmf(2, 10, 0.5, loc=0)
pmf_1 = binom.pmf(1, 10, 0.5, loc=0)
pmf_0 = binom.pmf(0, 10, 0.5, loc=0)
p_pmf = pmf_0 + pmf_1 + pmf_2 + pmf_3 + pmf_4

print(p_pmf)