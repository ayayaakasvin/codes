#include <string>
#include <set>
#include <vector>

std::vector <char> characters_of_string(std::string some_string) {
    std::set <char> set_of_characters;
    for (auto &&i : some_string)
    {
        set_of_characters.insert(i);
    }
    
    std::vector <char> result(set_of_characters.begin(), set_of_characters.end());
    return result;
}

bool solve(std::string s){
    std::vector <char> characters = characters_of_string(s);

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < characters.size(); j++)
        {
            std::string temp_s = s;
            if (temp_s[i] != characters[j])
            {
                temp_s[i] = characters[j];
                std::string reversed_temp_s(temp_s.rbegin(), temp_s.rend());
                if (temp_s == reversed_temp_s)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}