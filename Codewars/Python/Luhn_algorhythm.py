def validate(n):
    array = [int(x) for x in str(n)]
    array = list(reversed(array))

    for i in range(len(array)):
        if i % 2 == 1 and array[i] * 2 > 9:
            array[i] = (array[i] * 2) % 10 + (array[i] * 2) // 10
        elif i % 2 == 1:
            array[i] *= 2

    return sum(array) % 10 == 0  
