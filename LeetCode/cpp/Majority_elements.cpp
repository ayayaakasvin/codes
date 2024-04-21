#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map <int, int> elements;
        for (int i = 0; i < nums.size(); i++)
        {
            elements[nums[i]]++;
        }
        
        int size_of_nums = nums.size() / 2;
        for (auto &&i : elements)
        {
            if (i.second >= size_of_nums)
            {
                return i.first;
            }
        }
        
        return 0;
    }
};