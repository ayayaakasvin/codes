#include <string>

long long filter_string(const std::string &value)
{
    std::string result = "";
    for (auto &&i : value)
    {
        if (isdigit(i))
        {
            result.push_back(i);
        }
    }
    
    return result.length() > 0 ? result.length() > 1 ? std::stoll(result) : result[0] - '0' : -1;
}