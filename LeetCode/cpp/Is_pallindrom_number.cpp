#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);
        std::string s_reverse(s.rbegin(), s.rend());
        return s == s_reverse;
    }
};

int main () {
    Solution Jokerge;
    std::cout << Jokerge.isPalindrome(12321);
    std::cout << Jokerge.isPalindrome(1);
    std::cout << Jokerge.isPalindrome(321);

    return 0;
}w