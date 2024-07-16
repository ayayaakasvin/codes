#include <vector>
#include <unordered_map>

class Solution {
    public:
        bool containsDuplicate(std::vector<int>& nums) {
            std::unordered_map<int, int> mapOfAppereance;

            for (int i = 0; i < nums.size(); i++)
            {
                mapOfAppereance[nums[i]]++;

                if (mapOfAppereance[nums[i]] > 1)
                {
                    return 1;
                }
            }
            
            return false;
        }   
};