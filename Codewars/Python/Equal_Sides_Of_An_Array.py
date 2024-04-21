def find_even_index(arr):
    for x in range(len(arr)):
        first_part_of_arr = arr[0:x]
        second_part_of_arr = arr[x + 1:]
        if sum(first_part_of_arr) == sum(second_part_of_arr):
            return x
    return -1