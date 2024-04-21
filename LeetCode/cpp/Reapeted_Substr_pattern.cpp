#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        for (size_t i = 1; i <= s.length() / 2; i++)
        {
            if (s.length() % i == 0)
            {
                std::string substr_pattern = s.substr(0, i);
                std::string repeat = "";
                for (size_t j = 0; j < s.length() / i; j++)
                {
                    repeat += substr_pattern;
                }

                if (repeat == s)
                {
                    return 1;
                }
            }
        }

        return 0;
    }
};

int main () {
    Solution Solution;
    std::cout << Solution.repeatedSubstringPattern("abab");
    std::cout << Solution.repeatedSubstringPattern("aba");
    std::cout << Solution.repeatedSubstringPattern("abcabcabcabc");
}