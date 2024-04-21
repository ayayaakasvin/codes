#include <string>
#include <set>
#include <algorithm>

std::string disemvowel(const std::string& str) {
    std::set <char> vowels = {'a', 'e', 'u', 'i', 'o', 'A', 'E', 'U', 'I', 'O'};
    std::string copy_of_input = str;
    for (auto &&i : vowels)
    {
        auto it = std::find_if(copy_of_input.begin(), copy_of_input.end(), [i](const char& a){return a == i;});

        while (it != copy_of_input.end())
        {
            copy_of_input.erase(it);
            it = std::find_if(copy_of_input.begin(), copy_of_input.end(), [i](const char& a){return a == i;});
        }
    }

    return copy_of_input;
}