def get_integer_input(prompt):
  """Gets an integer input from the user with error handling."""
  while True:
    try:
      return int(input(prompt))
    except ValueError:
      print("Invalid input. Please enter an integer.")

def perform_operation(choice, num1, num2):
  """Performs the selected operation on the given numbers."""
  if choice == 1:
    return num1 + num2
  elif choice == 2:
    return num1 - num2
  elif choice == 3:
    return num1 * num2
  elif choice == 4:
    if num2 == 0:
      raise ZeroDivisionError("Cannot divide by zero.")
    return num1 / num2
  else:
    raise ValueError("Invalid choice.")

while True:
  print("\nMenu:")
  print("1. Addition")
  print("2. Subtraction")
  print("3. Multiplication")
  print("4. Division")
  print("5. Exit")

  try:
    choice = get_integer_input("Enter your choice (1-5): ")

    if choice == 5:
      break

    if choice in range(1, 5):
      num1 = get_integer_input("Enter the first number: ")
      num2 = get_integer_input("Enter the second number: ")

      result = perform_operation(choice, num1, num2)
      print("Result:", result)
    else:
      print("Invalid choice. Please enter a number between 1 and 5.")

  except ValueError as e:
    print("Error:", e)
  except ZeroDivisionError as e:
    print("Error:", e)