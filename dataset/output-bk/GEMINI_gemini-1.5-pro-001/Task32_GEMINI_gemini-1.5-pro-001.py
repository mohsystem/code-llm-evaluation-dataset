def calculate_years(principal, interest, tax, desired):
    years = 0
    while principal < desired:
        principal += (principal * interest) * (1 - tax)
        years+=1
    return years

if __name__ == "__main__":
    principal = float(input())
    interest = float(input())
    tax = float(input())
    desired = float(input())

    result = calculate_years(principal, interest, tax, desired)
    print(result)