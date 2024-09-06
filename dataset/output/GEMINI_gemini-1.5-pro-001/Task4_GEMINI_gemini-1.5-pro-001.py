def is_isogram(string):
  seen = set()
  for char in string.lower():
    if char in seen:
      return False
    seen.add(char)
  return True