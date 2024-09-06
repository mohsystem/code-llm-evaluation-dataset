def calculate_years(P, I, T, D):
    years = 0
    while P < D:
        P += P * I * (1 - T)
        years += 1
    return years

P = 1000.00
I = 0.05
T = 0.18
D = 1100.00
print(calculate_years(P, I, T, D))