def get_matrix(n):
    answer = []
    for i in range(n):
        temp_array = []
        for j in range(n):
            if i == j:
                temp_array.append(1)
            else:
                temp_array.append(0)
        answer.append(temp_array)

    return answer