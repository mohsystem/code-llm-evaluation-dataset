def solution(string, ending):
  return string.endswith(ending)

if __name__ == "__main__":
  print(solution('abc', 'bc')) # True
  print(solution('abc', 'd')) # False