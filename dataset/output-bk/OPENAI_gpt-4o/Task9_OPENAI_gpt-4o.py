def odd_or_even(lst):
    _sum = sum(lst)
    return "even" if _sum % 2 == 0 else "odd"

# Example input list
lst = [0, -1, -5]
print(odd_or_even(lst))