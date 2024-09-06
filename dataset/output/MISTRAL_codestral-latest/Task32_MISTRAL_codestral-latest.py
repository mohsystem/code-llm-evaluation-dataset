def calculate_years(principal, interest, tax, desired):
    years = 0
    while principal < desired:
        interest_earned = principal * interest
        tax_amount = interest_earned * tax
        principal += interest_earned - tax_amount
        years += 1
    return years