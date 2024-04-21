def dup(arry):
    for i in range(len(arry)):
        j = 1
        while j < len(arry[i]) - 1:
            if arry[i][j] == arry[i][j + 1] or arry[i][j] == arry[i][j - 1]:
                arry[i] = arry[i][:j] + arry[i][j + 1:]
                j -= 1
            j += 1
    
    return arry