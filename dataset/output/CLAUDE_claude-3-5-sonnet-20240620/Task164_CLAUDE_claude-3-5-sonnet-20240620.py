
def last_name_len_sort(names):
    return sorted(names, key=lambda x: (len(x.split()[-1]), x.split()[-1]))

# Example usage
names = [
    "Jennifer Figueroa",
    "Heather Mcgee",
    "Amanda Schwartz",
    "Nicole Yoder",
    "Melissa Hoffman"
]
print(last_name_len_sort(names))
