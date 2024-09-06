def calculate_years(P, I, T, D):
    Y = 0
    while P < D:
        interest = P * I
        tax = interest * T
        P += interest - tax
        Y += 1
    return Y