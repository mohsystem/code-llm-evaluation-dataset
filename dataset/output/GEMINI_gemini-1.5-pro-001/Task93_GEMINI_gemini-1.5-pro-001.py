def sort_key_value_file(file_path):
  """Reads a file containing key-value pairs, sorts them by key, and prints the sorted pairs.

  Args:
    file_path: The path to the input file.
  """

  key_value_pairs = {}
  with open(file_path, 'r') as f:
    for line in f:
      key, value = line.strip().split(" ", 1)
      key_value_pairs[key] = value

  for key in sorted(key_value_pairs):
    print(f"{key} {key_value_pairs[key]}")


if __name__ == "__main__":
  # Replace "input.txt" with the actual input file name
  input_file_path = "input.txt"
  sort_key_value_file(input_file_path)