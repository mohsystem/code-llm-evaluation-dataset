def remove_smallest(numbers):
    if not numbers:
        return []
    smallest = min(numbers)
    return [num for num in numbers if num != smallest or numbers.remove(smallest)]