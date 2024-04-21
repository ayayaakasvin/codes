#include <string>
#include <unordered_map>

bool scramble(const std::string& s1, const std::string& s2){
    if (s2.length() > s1.length())
    {
        return 0;
    }
    std::unordered_map <char, int> s1_copy;
    for (char c : s1)
    {
        s1_copy[c]++;
    }
    
    for (char c : s2)
    {
        std::unordered_map <char, int>::iterator it = s1_copy.find(c);

        if (it == s1_copy.end() || it->second == 0)
        {
            return false;
        }
        it->second--;
    }
    

    return true;
}