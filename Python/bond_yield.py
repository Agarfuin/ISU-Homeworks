def bond_yield(T, c, A, m, P):
    cp = c * A
    ytm = (cp+((A-P)/T))/((A+P)/2)
    ytm = ytm / m
    print(f'Bond yield equals to: {ytm:.4f}')
    return ytm


T = 7
c = 0.15
A = 1000
m = 2
P = 850
bond_yield(T, c, A, m, P)
