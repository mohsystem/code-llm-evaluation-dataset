
def remove_smallest(numbers):
    if not numbers:
        return []
    
    result = numbers.copy()
    min_index = result.index(min(result))
    result.pop(min_index)
    return result
