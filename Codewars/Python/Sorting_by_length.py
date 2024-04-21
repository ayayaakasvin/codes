def sort_by_length(arr):
    arr = sorted(arr, key=lambda x:(len(x)))
    return arr
