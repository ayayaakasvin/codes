def solution(s):
    if len(s) % 2 == 1:
        s += '_'
    some_array = []

    for i in range (len(s) // 2):
        some_array.append(s[0:2])
        s = s[2::]
    
    return some_array