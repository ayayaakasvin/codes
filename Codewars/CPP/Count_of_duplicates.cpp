#include <string>
#include <algorithm>
#include <map>


std::size_t duplicateCount(const std::string& in)
{
    std::string in_copy = in;
    for (auto &&i : in_copy)
    {
        if (i >= 'A' || i <= 'Z')
        {
            i = std::tolower(static_cast<unsigned char>(i));
        }
    }
    
    std::map <char, int> count_of_char;

    for (auto &&i : in_copy)
    {
        count_of_char[i]++;
    }
    
    for (auto i = count_of_char.begin(); i != count_of_char.cend();)
    {
        if (i->second == 1)
        {
            count_of_char.erase(i++);
        }
        else
        {
            ++i;
        } 
    }
    
    if (count_of_char.empty())
    {
        return 0;
    }
    
    return count_of_char.size();
}