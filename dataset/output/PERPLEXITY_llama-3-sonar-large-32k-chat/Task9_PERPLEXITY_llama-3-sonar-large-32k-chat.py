def odd_or_even(arr):
    return "even" if sum(arr) % 2 == 0 else "odd"

print(odd_or_even([0]))  # Output: "even"
print(odd_or_even([0, 1, 4]))  # Output: "odd"
print(odd_or_even([0, -1, -5]))  # Output: "even"