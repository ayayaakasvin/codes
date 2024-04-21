#include <algorithm>
#include <string>

std::string solve(std::string s) {
    std::string s_reversed(s.begin(), s.end());
    std::reverse(s_reversed.begin(), s_reversed.end());
    
    if (s == s_reversed)
    {
        return "OK";
    }

    for (int i = 0; i < s.length(); i++)
    {
        std:: string temp_s = s;
        temp_s.erase(temp_s.begin() + i);
        std:: string temp_reversed_s(temp_s.rbegin(), temp_s.rend());
        if (temp_reversed_s == temp_s)
        {
            return "remove one";
        }
        
    }

    return "not possible";
}