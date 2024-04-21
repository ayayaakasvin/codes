def merge_arrays(arr1, arr2):
    arr1.extend(arr2)
    arr1 = list(set(arr1))
    arr1.sort()
    return arr1

some_array_1, some_array_2 = [1, 3, 5, 7, 9, 11, 12], [1, 2, 3, 4, 5, 10, 12]
print(merge_arrays(some_array_1, some_array_2))