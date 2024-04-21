#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        int counter = 0;
        std::unordered_map <char, int> s_char_counter;
        
        for (char i : s)
        {
            s_char_counter[i]++;
        }
        
    }
};

int main () {
    Solution Jokerge;

    std::cout << Jokerge.minSteps("aba", "bab");

    return 0;
}