#include <iostream>
#include <string>
#include <vector>

std::vector<int> digitize(unsigned long n) 
{        
    std::vector <int> result;
    std::string str_digit = std::to_string(n);
    std::string reversed_n(str_digit.rbegin(), str_digit.rend());

    for (auto i = reversed_n.begin(); i != reversed_n.end(); ++i)
    {
        result.push_back(*i - '0');
    }
    
    return result;
}