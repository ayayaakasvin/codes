def sum_of_differences(arr):
    arr.sort(reverse = True)

    counter = 0
    i = 0
    while i < len(arr) - 1:
        counter += arr[i] - arr[i + 1]
        i += 1

    return counter