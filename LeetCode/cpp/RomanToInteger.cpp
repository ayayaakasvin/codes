#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map <char, int> Roman_integers{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int counter = 0;
        for (size_t i = 0; i < s.length() - 1; i++)
        {
            Roman_integers[s[i]] < Roman_integers[s[i + 1]] ? counter -= Roman_integers[s[i]] : counter += Roman_integers[s[i]];
        }
        counter += Roman_integers[s.back()];

        return counter;
    }
};

int main () {
    Solution Jokerge;
    std::cout << Jokerge.romanToInt("III") << std::endl;
    std::cout << Jokerge.romanToInt("LVIII") << std::endl;
    std::cout << Jokerge.romanToInt("MCMXCIV") << std::endl;

    return 0;
}