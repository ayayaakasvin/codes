def isVowel (char : str) -> bool:
    Vowels = "aeuio"
    if Vowels.find((char.lower())) != -1:
        return True
    
    return False

def disemvowel(string_):
    return "".join(char for char in string_ if not isVowel(char))