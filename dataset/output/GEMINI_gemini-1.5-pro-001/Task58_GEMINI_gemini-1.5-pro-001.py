def XO(str):
  str = str.lower()
  return str.count('x') == str.count('o')

print(XO("ooxx")) # true
print(XO("xooxx")) # false
print(XO("ooxXm")) # true
print(XO("zpzpzpp")) # true
print(XO("zzoo")) # false