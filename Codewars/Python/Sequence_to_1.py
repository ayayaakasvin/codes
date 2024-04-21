def seq_to_one(n):
    result = [n]
    while n != 1:
        if n > 1:
            n -= 1
            result.append(n)
        else:
            n += 1
            result.append(n)

    return result