#include <string>
#include <sstream>
#include <iostream>

std::string reverse_words(std::string str)
{
    std::string temp, result;
    std::stringstream ss(str);

    while (getline(ss, temp, ' '))
    {
        std::string reverse_temp(temp.rbegin(), temp.rend());
        result += reverse_temp + ' ';
    }
    
    if (!result.empty() && str.back() != ' ')
    {
        result.pop_back();
    }
    
    return result;
}

int main () {
    std::cout << reverse_words("double  spaces");

    return 0;
}