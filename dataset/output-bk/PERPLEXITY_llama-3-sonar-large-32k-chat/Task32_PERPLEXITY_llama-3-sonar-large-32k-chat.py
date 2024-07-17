def calculateYears(principal, interestRate, taxRate, desiredSum):
    years = 0
    while principal < desiredSum:
        interest = principal * interestRate
        tax = interest * taxRate
        principal += interest - tax
        years += 1
    return years

principal = 1000.00
interestRate = 0.05
taxRate = 0.18
desiredSum = 1100.00
print(calculateYears(principal, interestRate, taxRate, desiredSum))