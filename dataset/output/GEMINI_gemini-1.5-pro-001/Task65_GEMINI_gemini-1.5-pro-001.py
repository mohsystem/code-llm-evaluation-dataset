import sys

def read_file(filename):
  """Reads the content of a file.

  Args:
    filename: The name of the file to read.

  Returns:
    The content of the file as a string, or None if an error occurred.
  """
  try:
    with open(filename, 'r') as f:
      return f.read()
  except FileNotFoundError:
    print(f"Error: File '{filename}' not found.")
    return None
  except Exception as e:
    print(f"Error reading file '{filename}': {e}")
    return None

if __name__ == "__main__":
  if len(sys.argv) < 2:
    print("Usage: python your_script_name.py <filename>")
    sys.exit(1)

  filename = sys.argv[1]
  file_content = read_file(filename)

  if file_content:
    print(file_content)