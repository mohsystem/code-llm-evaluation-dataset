def remove_smallest(numbers):
    if not numbers:
        return numbers
    min_index = numbers.index(min(numbers))
    return numbers[:min_index] + numbers[min_index + 1:]

numbers = [5, 3, 2, 1, 4]
print(remove_smallest(numbers))