def calculate_years(principal, desired, interest, tax):
    years = 0
    while principal < desired:
        principal += (principal * interest) * (1 - tax)
        years += 1
    return years