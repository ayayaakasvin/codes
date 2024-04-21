#include <string>
#include <algorithm>

std::string increment_digit (std::string digit) {
    int result = std::stoi(digit);
    ++result;

    return std::to_string(result);
}

std::string incrementString(const std::string &str)
{
    if (std::isalpha(str.at(str.length() - 1)) || str.empty())
    {
        return str + '1';
    }
    
    std::string digits;
    for (int i = str.length() - 1; i >= 0 && !std::isalpha(str.at(i)); i--)
    {
        digits.push_back(str.at(i));
    }

    for (int i = 1; i < digits.length() - 1; i--)
    {
        if (digits[i - 1] == '0' && digits[i + 1] != '0')
        {
            digits.erase(digits.begin(), digits.begin() + i);
            break;
        }
    }
    

    std::string temp = increment_digit(digits);
    std::string str_till_digit(str.begin(), str.begin() + (str.length() - digits.length()));

    return str_till_digit + temp;
}