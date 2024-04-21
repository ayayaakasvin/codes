#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int pos = 0;

        for (int i = 0; i < s.length(); i++)
        {
            pos = t.find(s[i], pos);
            if (pos == t.npos)
            {
                return false;
            }

            pos++;
        }
        
        return true;
    }
};