def remove_smallest(numbers):
    if len(numbers) < 1:
        return []
    
    copy_numbers = numbers.copy()
    copy_numbers.remove(min(numbers))

    return copy_numbers