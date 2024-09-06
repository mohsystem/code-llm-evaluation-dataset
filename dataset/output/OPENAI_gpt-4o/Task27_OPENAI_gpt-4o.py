def find_outlier(integers):
    odds = [i for i in integers if i % 2 != 0]
    evens = [i for i in integers if i % 2 == 0]
    return odds[0] if len(odds) == 1 else evens[0]

# Test case
print(find_outlier([2, 4, 0, 100, 4, 11, 2602, 36]))  # Output: 11
print(find_outlier([160, 3, 1719, 19, 11, 13, -21]))  # Output: 160