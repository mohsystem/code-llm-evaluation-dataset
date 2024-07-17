def gcd(a, b):
  while b:
    a, b = b, a % b
  return a

if __name__ == "__main__":
  num1 = int(input("Enter first number: "))
  num2 = int(input("Enter second number: "))
  print("GCD:", gcd(num1, num2))