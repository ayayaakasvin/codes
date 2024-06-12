#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

class Solution {
public:
    bool isMonotonic(std::vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                increasing = false;
            }
            if (nums[i] < nums[i + 1]) {
                decreasing = false;
            }
        }

        return increasing || decreasing;
    }
};