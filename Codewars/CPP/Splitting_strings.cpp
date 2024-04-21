#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> solution(const std::string &s)
{
    std::vector <std::string> kekw;
    std::string somestring = s;
    if (somestring.length() % 2 == 1)
    {
        somestring += '_';
    }
    
    while (!somestring.empty())
    {
        kekw.push_back(somestring.substr(0, 2));
        somestring.erase(0, 2);
    }
    
    return kekw;
}

int main () {
    std::vector<std::string> soluted = solution("aabbc");
    for (std::string s : soluted)
    {
        std::cout << s << ' ';
    }
    return 0;
}