#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (target <= nums[i])
            {
                return i;
            }
            
        }
        
        return nums.size();
    }
};