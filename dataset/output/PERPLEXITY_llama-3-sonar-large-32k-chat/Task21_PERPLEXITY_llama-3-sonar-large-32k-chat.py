def remove_smallest(numbers):
    if not numbers:
        return []
    min_index = numbers.index(min(numbers))
    return numbers[:min_index] + numbers[min_index+1:]