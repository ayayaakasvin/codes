#include <string>
#include <sstream>
#include <vector>
#include <iostream>

class Tokenizing {
    public:
        std::vector<std::string> tokenizing_of_the_line (std::string input) {
        std::string temp_string;
        std::stringstream ss(input);
        std::vector <std::string> result;

        while (getline(ss, temp_string, ' '))
        {
            result.push_back(temp_string);
        }
        
        return result;
    }
};

std::string pig_it(std::string str)
{
    Tokenizing token_string_space;
    std::vector <std::string> already_tokenized_string = token_string_space.tokenizing_of_the_line(str);
    std::string result = "";

    for (std::string i : already_tokenized_string)
    {
        if (isalpha(i[0]))
        {
            char c = i[0];
            i.erase(0, 1);
            int j = 0;
            while (ispunct(i[i.length() - j]))
            {
                j++;
            }
            
            i.insert(i.length() - j, 1, c);
            i += "ay";
        }

        result += i + ' ';
    }
    
    if (!result.empty())
    {
        result.pop_back();
    }
    
    return result;
}

int main () {
    std::string Jokerge = pig_it("Hello world!");
    std::cout << Jokerge;

    return 0;
}