def remove_smallest(numbers):
    if numbers:
        numbers.remove(min(numbers))
    return numbers