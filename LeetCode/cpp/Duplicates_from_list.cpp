#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        for (size_t i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i - 1] == nums[i])
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        
        return nums.size();
    }
};

class Amogus {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::set <int> result{nums.begin(), nums.end()};
        nums = {result.begin(), result.end()};

        return nums.size();
    }
};

int main () {
    Solution Jokerge;
    std::vector <int> lol = {1, 1, 2, 3};
    std::cout << Jokerge.removeDuplicates(lol);
}