# Python
def gcd(a, b):
    while(b):
        a, b = b, a % b
    return a

# Test the function
num1 = int(input("Enter first number: "))
num2 = int(input("Enter second number: "))
print("The GCD is", gcd(num1, num2))