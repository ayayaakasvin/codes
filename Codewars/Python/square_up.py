def square_up(n):
    if n == 1:
        return [1]
    result = []
    for i in range(n, 0, -1):
        for j in range (1, n + 1):
            if i >= j:
                result.append(j)
            else:
                result.append(0)

    result.reverse()
    return result