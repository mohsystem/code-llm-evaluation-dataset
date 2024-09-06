def sum_is_odd_or_even(arr):
    if sum(arr) % 2 == 0:
        return "even"
    else:
        return "odd"

print(sum_is_odd_or_even([0]))      # even
print(sum_is_odd_or_even([0, 1, 4])) # odd
print(sum_is_odd_or_even([0, -1, -5])) # even