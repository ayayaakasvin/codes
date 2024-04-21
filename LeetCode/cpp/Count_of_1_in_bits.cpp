#include <cstdint>
#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        std::string str_bits  = std::to_string(n);
        std::cout << str_bits << std::endl;
        int counter = std::count(str_bits.begin(), str_bits.end(), '1');
        return counter;
    }
};

int main () {
    Solution Jokerge;
    std::cout << Jokerge.hammingWeight(00000000000000000000000000001011) << std::endl;

    return 0;
}