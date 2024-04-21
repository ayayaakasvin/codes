def even_or_odd(number):
    Gandon = {
        True : "Even",
        False : "Odd"
    }
    return Gandon[number % 2 == 0]