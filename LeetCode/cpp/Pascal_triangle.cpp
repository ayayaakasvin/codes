#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result{{1}};
        for (int i = 1; i < numRows; i++)
        {
            std::vector<int> pascal_number{1};
            for(int j = 1; j <= i-1; j++){
                pascal_number.push_back(result[i-1][j-1]+result[i-1][j]);
            }
            pascal_number.push_back(1);
            result.push_back(pascal_number);
        }
        
        return result;
    }
};

int main () {
    Solution Jokerge;
    std::vector <std::vector <int>> answer = Jokerge.generate(69);

    for (auto &&i : answer)
    {
        for (auto &&j : i)
        {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }
    
}