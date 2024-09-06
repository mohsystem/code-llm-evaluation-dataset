import ctypes

lib = ctypes.CDLL("solution.so")

a = int(input("Enter first number: "))
b = int(input("Enter second number: "))

result = lib.gcd(a, b)
print("Greatest Common Divisor:", result)