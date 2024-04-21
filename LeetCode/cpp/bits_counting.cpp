#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector <int> result;
        for (size_t i = 0; i <= n; i++)
        {
            std::string binary_version = std::bitset <32>(i).to_string();
            result.push_back(std::count(binary_version.begin(), binary_version.end(), '1'));
        }
        
        return result;
    }
};

int main () {
    Solution Jokerge;
    std::vector <int> answer = Jokerge.countBits(5);

    for (auto &&i : answer)
    {
        std::cout << i << ' ';
    }
    
    return 0;
}