import sys

def read_file(file_path):
  """Reads the content of a file.

  Args:
    file_path: The path to the file.

  Returns:
    The content of the file as a string.
  """
  try:
    with open(file_path, 'r') as f:
      content = f.read()
    return content
  except FileNotFoundError:
    print(f"Error: File not found: {file_path}")
    sys.exit(1)

if __name__ == "__main__":
  if len(sys.argv) < 2:
    print("Error: Please provide the file path as a command-line argument.")
    sys.exit(1)

  file_path = sys.argv[1]
  file_content = read_file(file_path)
  print(file_content)