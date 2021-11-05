from scipy import stats
import math

result = 0
for j in range(1000):
    rv = stats.expon.rvs(scale=0.2, size=100)
    sum = 0
    for i in range(100):
        sum = sum + rv[i]

    expectation = sum / 100
    if expectation > 0.21:
        result += 1

psim = float(result) / 1000.0
print(round(psim, 4))

z = (0.21 - 0.2) / (0.2 / math.sqrt(100))
pclt = 1 - stats.norm.cdf(z)
print(round(pclt, 4))

pgam = 1 - stats.gamma.cdf(0.21, 1, scale=0.2)
print(round(pgam, 4))