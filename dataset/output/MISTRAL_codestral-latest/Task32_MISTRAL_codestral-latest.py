# Python
def calculate_years(principal, interest, tax, desired):
    years = 0
    while principal < desired:
        interest_earned = principal * interest
        tax_amount = interest_earned * tax
        principal += interest_earned - tax_amount
        years += 1
    return years

print(calculate_years(1000.0, 0.05, 0.18, 1100.0))