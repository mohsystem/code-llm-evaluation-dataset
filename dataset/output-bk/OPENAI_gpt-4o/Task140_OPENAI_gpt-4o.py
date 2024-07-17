x = float(input("Enter first number: "))
y = float(input("Enter second number: "))
op = input("Enter operator (+, -, *, /): ")

if op == '+':
    print(f"Result: {x + y}")
elif op == '-':
    print(f"Result: {x - y}")
elif op == '*':
    print(f"Result: {x * y}")
elif op == '/':
    if y != 0:
        print(f"Result: {x / y}")
    else:
        print("Cannot divide by zero")
else:
    print("Invalid operator")