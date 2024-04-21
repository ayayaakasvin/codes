def scramble(s1, s2):
    if len(s1) < len(s2):
        return False
    dic = {}
    for i in s1:
        dic[i] =  dic.get(i, 0) + 1
    for i in s2:
        if i not in dic or dic[i] == 0:
            return False
        else:
            dic[i] =  dic.get(i, 0) - 1
    return True