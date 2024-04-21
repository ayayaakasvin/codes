#include <string>
#include <iostream>

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        int pos = 0;
        pos = word.find(ch, pos);
        if (pos == std::string::npos)
        {
            return word;
        }

        std::string prefix = word.substr(0, pos + 1);
        word = word.substr(pos + 1);
        std::string reversed_pref(prefix.rbegin(), prefix.rend());
        
        return reversed_pref + word; 
    }
};

int main () {
    Solution Jokerge;
    std::cout << Jokerge.reversePrefix("abcde", 'd') << std::endl;

    return 0;
}