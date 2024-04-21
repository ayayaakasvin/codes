from math import floor


def gps(s, x):
    if len(x) <= 1:
        return 0;
    speed_array = []
    for i in range(1, len(x)):
        speed_array.append((3600 * (x[i] - x[i - 1])) / s)
    answer = int(floor(max(speed_array)))
    return answer