def solve(s):
    s_set = set(s)
    for i in range(len(s)):
        for j in s_set:
            temp_s = s
            if temp_s[i] != j:
                temp_s = temp_s[:i] + j + temp_s[i + 1:]
                if (temp_s == temp_s[::-1]):
                    return True
    return False