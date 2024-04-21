#include <string>

class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        for (char i : t)
        {
            int pos = 0;
            pos = s.find(i, pos);
            if (pos == std::string::npos)
            {
                return i;
            }

            pos++;
        }

        return t[0];
    }
};