import string

def is_pangram(text):
  """
  Check if a string is a pangram.

  Args:
    text: The string to check.

  Returns:
    True if the string is a pangram, False otherwise.
  """
  text = text.lower()
  return set(string.ascii_lowercase) <= set(text)

if __name__ == "__main__":
    text = "The quick brown fox jumps over the lazy dog"
    print(is_pangram(text))