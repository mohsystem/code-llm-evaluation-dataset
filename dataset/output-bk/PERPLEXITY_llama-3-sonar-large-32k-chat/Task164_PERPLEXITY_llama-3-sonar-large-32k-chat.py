def lastNameLensort(names):
    return sorted(names, key=lambda x: (len(x.split()[-1]), x.split()[-1]))

print(lastNameLensort([
  "Jennifer Figueroa",
  "Heather Mcgee",
  "Amanda Schwartz",
  "Nicole Yoder",
  "Melissa Hoffman"
]))