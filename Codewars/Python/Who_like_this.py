def likes(names):
    n = len(names)

    cases = [
        "no one likes this",
        f"{names[0]} likes this" if n >= 1 else "",
        f"{names[0]} and {names[1]} like this" if n >= 2 else "",
        f"{names[0]}, {names[1]} and {names[2]} like this" if n >= 3 else "",
        f"{names[0]}, {names[1]} and {n - 2} others like this" if n > 3 else ""
    ]

    return cases[min(4, len(names))]