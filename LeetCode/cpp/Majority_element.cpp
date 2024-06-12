#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map <int, int> appereance_of_nums_map;
        std::pair <int, int> major_element = std::make_pair(nums[0], 1);
        for (int i = 0; i < nums.size(); i++)
        {
            appereance_of_nums_map[nums[i]]++;
            if (appereance_of_nums_map[nums[i]] > major_element.second)
            {
                major_element = {nums[i], appereance_of_nums_map[nums[i]]};
            }
        }
        
        return major_element.first;
    }
};

int some_function () {
    Solution Jokerge;
    std::vector <int> s{3, 2, 3};
    std::cout << Jokerge.majorityElement(s) << std::endl;
    return 0;
}