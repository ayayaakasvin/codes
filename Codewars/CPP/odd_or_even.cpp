#include <string>
#include <map>
#include <iostream>

std::string even_or_odd(int number) 
{
    std::map<bool, std::string> Jokerge {
        {true, "Even"}, {false, "Odd"}
    };
    return Jokerge[(number % 2 == 0)];
}

int main () {
    std::cout << even_or_odd(5);
    return 0;
}