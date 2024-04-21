def solve(s):
    if s == s[::-1]:
        return "OK"
    for i in range(len(s)):
        s_temp = s[:i] + s[i + 1:]
        print(s_temp)
        if s_temp == s_temp[::-1]:
            return "remove one"
    
    return "not possible"