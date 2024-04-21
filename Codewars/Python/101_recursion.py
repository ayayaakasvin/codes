def solve(a,b):
    if a == b or a == 0 or b == 0:
        return [a, b]
    elif a >= 2 * b:
        a -= 2 * b
        return solve(a, b)
    elif b >= 2 * a:
        b -= 2 * a
        return solve(a, b)
    
    return [a, b]