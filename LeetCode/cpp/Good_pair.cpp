#include <vector>
#include <iostream>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        int good_pair_counter = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    good_pair_counter++;
                }
            }
        }
        
        return good_pair_counter;
    }
};

int main () {
    Solution Jokerge;
    std::vector <int> a{1, 1, 1, 1};
    std::vector <int> b{1,2,3,1,1,3};

    std::cout << Jokerge.numIdenticalPairs(a) << std::endl;
    std::cout << Jokerge.numIdenticalPairs(b) << std::endl;

    return 0;
}