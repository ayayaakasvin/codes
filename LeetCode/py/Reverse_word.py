class Solution:
    def reverseWords(self, s: str) -> str:
        result = ""
        for i in list(s.split()):
            result += i[::-1] + ' '
        
        return result[:-1:]