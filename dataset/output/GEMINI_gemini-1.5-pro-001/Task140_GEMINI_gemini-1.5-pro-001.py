num1 = float(input("Enter the first number: "))
op = input("Enter the operator (+, -, *, /): ")
num2 = float(input("Enter the second number: "))

if op == "+":
    print(num1 + num2)
elif op == "-":
    print(num1 - num2)
elif op == "*":
    print(num1 * num2)
elif op == "/":
    if num2 == 0:
        print("Division by zero not allowed")
    else:
        print(num1 / num2)
else:
    print("Invalid input")