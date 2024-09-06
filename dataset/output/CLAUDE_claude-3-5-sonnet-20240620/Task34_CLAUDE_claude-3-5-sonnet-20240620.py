
def narcissistic(num):
    digits = [int(d) for d in str(num)]
    power = len(digits)
    return sum(d ** power for d in digits) == num

# Test cases
print(narcissistic(153))  # True
print(narcissistic(1652))  # False
