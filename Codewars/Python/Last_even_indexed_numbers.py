def even_numbers(arr,n):
    result = list("0" * n)
    i = len(arr) - 1
    j = n - 1
    while (j >= 0):
        if arr[i] % 2 == 0:
            result[j] = arr[i]
            j -= 1
        i -= 1
    return result