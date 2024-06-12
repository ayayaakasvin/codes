#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        std::vector <int> evens;
        std::vector <int> odds;
        std::copy_if(nums.begin(), nums.end(),std::back_inserter(evens), [](int a){return a % 2 == 0;});
        std::copy_if(nums.begin(), nums.end(), std::back_inserter(odds), [](int a){return a % 2 == 1;});

        evens.insert(evens.end(), odds.begin(), odds.end());
        return evens;
    }
};

int main () {
    Solution Jokerge;
    std::vector <int> array = {3,1,2,4,6,8,7};
    std::vector <int> result = Jokerge.sortArrayByParity(array);
    
    for (auto &&i : result)
    {
        std::cout << i << ' ';
    }

    return 0;    
}