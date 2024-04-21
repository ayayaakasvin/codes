#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        if (nums.size() == 1)
        {
            return nums;
        }
        
        std::vector <int> max_elements;
        for (unsigned long i = 0; i < nums.size() - k + 1; i++)
        {
            max_elements.push_back(*std::max_element(nums.begin() + i, nums.begin() + k + i));
        }

        return max_elements;
    }
};