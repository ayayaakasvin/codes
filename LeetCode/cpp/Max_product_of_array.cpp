#include <vector>
#include <iostream>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int max_num = nums[0], pre_max_num = nums[1];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] >= max_num)
            {
                pre_max_num = max_num;
                max_num = nums[i];
            }
            else if (nums[i] > pre_max_num)
            {
                pre_max_num = nums[i];
            }
        }

        return (max_num - 1) * (pre_max_num - 1);
    }
};

int main () {
    std::vector<int> numeros = {2, 5};
    Solution Jokerge;

    std::cout << Jokerge.maxProduct(numeros);

    return 0;
}