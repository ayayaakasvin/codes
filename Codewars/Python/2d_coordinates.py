def quadrant(x, y):
    kekq = {
        (1, 1) : 1,
        (-1, 1)  : 2,
        (-1, -1)  : 3,
        (1, -1)  : 4
    }
    return kekq[(x // abs(x), y // abs(y))]

print(quadrant(5, 3))