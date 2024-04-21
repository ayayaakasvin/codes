def solution(args):
    result = ""
    range_in_array = []
    for i in range(len(args) - 1):
        if (abs(args[i] - args[i + 1]) == 1) and (i < len(args) - 1):
            range_in_array.append(args[i])
        else:
            range_in_array.append(args[i])

            if len(range_in_array) >= 3:
                result += str(range_in_array[0]) + '-' + str(range_in_array[len(range_in_array) - 1]) + ','
            
            else:
                for j in range_in_array:
                    result += str(j) + ','
            
            range_in_array.clear()

    range_in_array.append(args[-1])
    if len(range_in_array) >= 3:
        result += str(range_in_array[0]) + '-' + str(range_in_array[-1]) + ','
    else:
        for j in range_in_array:
            result += str(j) + ','


    return result[:-1:]