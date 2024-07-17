def process_string(input_string):
  """
  Processes the input string (example: converts to uppercase).

  Args:
      input_string: The input string.

  Returns:
      The processed string.
  """
  return input_string.upper()

def main():
  """
  Main function to get input and process the string.
  """
  input_string = input("Enter a string: ")
  processed_string = process_string(input_string)
  print(f"Processed string: {processed_string}")

if __name__ == "__main__":
  main()