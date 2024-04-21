#include <numeric>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

std::vector <int> numbers_return_from_string (std::string s) {
    std::vector <int> result;
    
    for (unsigned long i = 0; i < s.length(); i++)
    {
        result.push_back(s[i] - '0');
    }
    
    return result;
}

bool narcissistic( int value ){
    std::string s = std::to_string(value);
    if (s.length() == 1)
    {
        return true;
    }
    
    std::vector <int> digits_of_s = numbers_return_from_string(s);
    int length_of_s = digits_of_s.size();

    return std::accumulate(digits_of_s.begin(), digits_of_s.end(), 0, [length_of_s](int& result, const int& a){return result + (pow(a, length_of_s));}) == stoi(s);
}