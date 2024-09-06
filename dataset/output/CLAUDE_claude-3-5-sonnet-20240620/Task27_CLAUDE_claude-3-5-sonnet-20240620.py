
def find_outlier(arr):
    evens = [x for x in arr if x % 2 == 0]
    odds = [x for x in arr if x % 2 != 0]
    return evens[0] if len(evens) == 1 else odds[0]

# Example usage
print(find_outlier([2, 4, 0, 100, 4, 11, 2602, 36]))  # Output: 11
print(find_outlier([160, 3, 1719, 19, 11, 13, -21]))  # Output: 160
