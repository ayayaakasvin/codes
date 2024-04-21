#include <string>
#include <sstream>

class Solution {
public:
    std::string tokenizing(std::string some_string) {
        std::string temp;
        std::stringstream ss(some_string);
        std::string result;

        while ((getline(ss, temp, ' ')))
        {
            std::string reversed_word(temp.rbegin(), temp.rend());
            result += reversed_word + ' ';
        }
        
        result.pop_back();
        return result;
    }

    std::string reverseWords(std::string s) {
        return tokenizing(s);
    }
};

// std::string reverse_words(std::string str)
// {
//     std::string temp, result;
//     std::stringstream ss(str);

//     while (getline(ss, temp, ' '))
//     {
//         std::string reverse_temp(temp.rbegin(), temp.rend());
//         result += reverse_temp + ' ';
//     }
    
//     if (!result.empty() && str.back() != ' ')
//     {
//         result.pop_back();
//     }
    
//     return result;
// }

// int main () {
//     std::cout << reverse_words("double  spaces");

//     return 0;
// }