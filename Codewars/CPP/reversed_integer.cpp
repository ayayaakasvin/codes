#include <string>

class Solution {
public:
    int reverse(long long x) {
        if (x == 0)
        {
            return 0;
        }
        else
        {
            while (x % 10 == 0)
            {
                x /= 10;
            }

            std::string temp = std::to_string(x);
            std::string reversed_number(temp.rbegin(), temp.rend());
            
            if (x > 0)
            {
                std::string temp = std::to_string(x);
                std::string reversed_number(temp.rbegin(), temp.rend());
                return std::stoll(reversed_number);
            }
            else if (x < 0)
            {
                return std::stoll(reversed_number.substr(0, reversed_number.length() - 1)) * (-1);
            }

            return 0;
        }
    }
};