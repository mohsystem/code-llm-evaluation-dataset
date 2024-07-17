def odd_or_even(array):
    return "even" if sum(array) % 2 == 0 else "odd"

array = [0, -1, -5]
print(odd_or_even(array))