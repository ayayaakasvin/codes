#include <string>
#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        return haystack.find(needle);
    }
};

int main () {
    Solution Jokerge;
    std::cout << Jokerge.strStr("Haystack", "Needle");
    std::cout << Jokerge.strStr("SadCat", "Cat");
    std::cout << Jokerge.strStr("SadCat", "Sad");

    return 0;
}