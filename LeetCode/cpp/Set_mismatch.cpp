#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        std::unordered_map <int, size_t> integer_count;
        int target_dupl, not_mentioned_number;

        for (int i : nums)
        {
            integer_count[i]++;
        }

        for (int i = 1; i <= nums.size(); i++)
        {
            if (integer_count[i] == 0)
            {
                not_mentioned_number = i;
            }
            
            if (integer_count[i] == 2)
            {
                target_dupl = i;
            }
            
        }
        
        
        return {target_dupl, not_mentioned_number};
    }
};