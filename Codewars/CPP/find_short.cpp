#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

std::vector <int> vectorOfWords (std::string words) {
    std::vector <int> result;
    std::string temp;
    std::stringstream ss(words);

    while (getline(ss, temp, ' '))
    {
        result.push_back(temp.length());
    }
    
    return result;
}

int find_short(std::string str)
{
    std::vector <int> lengthsOfWords = vectorOfWords(str);
    return *std::min_element(lengthsOfWords.begin(), lengthsOfWords.end());
}