#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map <char, int> appereance_of_character;

        for (int i = 0; i < s.length(); i++)
        {
            appereance_of_character[s[i]]++;
        }
        
        for (std::string::iterator i = s.begin(); i != s.end(); i++)
        {
            if (appereance_of_character[*i] == 1)
            {
                return s.find(*i);
            }
        }

        return -1;
    }
};

int main () {
    Solution Jokerge;
    std::cout << Jokerge.firstUniqChar("leetcode") << std::endl;

    return 0;
}