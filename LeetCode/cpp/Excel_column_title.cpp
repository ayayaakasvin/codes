#include <iostream>
#include <string>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        if (columnNumber > 26)
        {
            return std::to_string('A' + ((columnNumber - 1) % 26));
        }
        
        return convertToTitle(columnNumber / 26) + ((char)('A' + (columnNumber - 1) % 26));
    }
};

int main () {
    Solution Jokerge;
    std::cout << Jokerge.convertToTitle(1) << std::endl;
    std::cout << Jokerge.convertToTitle(26) << std::endl;
    std::cout << Jokerge.convertToTitle(27) << std::endl;
    std::cout << Jokerge.convertToTitle(28) << std::endl;
    std::cout << Jokerge.convertToTitle(701) << std::endl;

    return 0;
}