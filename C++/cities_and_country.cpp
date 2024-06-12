#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <vector>

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

int main () {
    int l;
    std::cin >> l;
    std::string line_for_input;
    std::unordered_map <std::string, std::string> map_for_calls;
    for (int i = 0; i < l; i++)
    {
        getline(std::cin, line_for_input);
        std::vector <std::string> temp_vector = tokenizing_of_the_line(line_for_input);
        for (int i = 1; i < temp_vector.size(); i++)
        {
            map_for_calls[temp_vector[i]] = temp_vector[0];
        }
    }
    
    int co;
    std::cin >> co;
    std::vector <std::string> answer;

    for (int i = 0; i < co; i++)
    {
        std::string city;
        std::cin >> city;
        answer.push_back(map_for_calls[city]);
    }
    
    for (int i = 0; i < co; i++)
    {
        std::cout << answer[i];
    }
    
    return 0;
}