def lastNameLensort(names):
    return sorted(names, key=lambda x: (len(x.split(' ')[1]), x.split(' ')[1]))

names = [
    "Jennifer Figueroa",
    "Heather Mcgee",
    "Amanda Schwartz",
    "Nicole Yoder",
    "Melissa Hoffman"
]

print(lastNameLensort(names))