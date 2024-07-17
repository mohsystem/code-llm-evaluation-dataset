def calculate_years(P, I, T, D):
    years = 0
    while P < D:
        interest = P * I
        after_tax = interest - (interest * T)
        P += after_tax
        years += 1
    return years

P = 1000.00
I = 0.05
T = 0.18
D = 1100.00
years = calculate_years(P, I, T, D)
print(years)