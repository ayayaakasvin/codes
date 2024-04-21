#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        int length_of_g = g.size();

        for (int i = 0; i < s.size(); i++)
        {
            std::vector<int>::iterator it = std::find(g.begin(), g.end(), s[i]);
            
            if (it != g.end())
            {
                g.erase(it);
            }
        }
        
        return length_of_g - g.size();
    }
};

int main () {
    std::vector <int> g = {1, 2, 3}, s = {1, 1};
    Solution Jokerge;

    std::cout << Jokerge.findContentChildren(g, s);

    return 0;
}