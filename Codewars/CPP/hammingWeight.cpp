#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

class Solution {
public:
    int hammingWeight(int n) {
        std::string binary = std::bitset<32>(n).to_string();
        return std::count(binary.begin(), binary.end(), '1');
    }
};

int main() {
    Solution Jokerge;
    std::cout << Jokerge.hammingWeight(2147483645) << std::endl;
    std::cout << Jokerge.hammingWeight(11) << std::endl;
    std::cout << Jokerge.hammingWeight(0) << std::endl;
    std::cout << Jokerge.hammingWeight(128) << std::endl;

    return 0;
}