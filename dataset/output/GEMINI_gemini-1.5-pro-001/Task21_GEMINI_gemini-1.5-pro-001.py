def remove_smallest(numbers):
    if not numbers:
        return []  # Return an empty list if the input is empty
    else:
        min_value = min(numbers)
        min_index = numbers.index(min_value)
        return numbers[:min_index] + numbers[min_index + 1:]


numbers = [2, 2, 1, 2, 1]
output = remove_smallest(numbers)
print(output)