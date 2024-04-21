#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <map>

std::string bitLetter(const std::vector<unsigned char> n){
    std::string answer = "";
    std::map <std::string, char> map_of_punctuation;
    map_of_punctuation["00"] = '\0';
    map_of_punctuation["01"] = ' ';
    map_of_punctuation["10"] = ',';
    map_of_punctuation["11"] = '.';
    
    for (unsigned long i = 0; i < n.size(); i++)
    {
        std::string binary_version = std::bitset <8>(n[i]).to_string();
        std::cout << binary_version << std::endl;
        std::string bits_of_char = binary_version.substr(3, 5);
        char Character_for_answer = (char)('a' + std::bitset<5>(std::string(bits_of_char)).to_ulong());
        if (binary_version[2] == '1')
        {
            Character_for_answer = std::toupper(Character_for_answer);
        }
        
        if (binary_version.substr(0, 2) == "00") 
        {
        answer.push_back(Character_for_answer);
        } 
        else 
        {
            if (map_of_punctuation[binary_version.substr(0, 2)] == ' ')
            {
                answer.push_back(map_of_punctuation[binary_version.substr(0, 2)]);
                answer.push_back(Character_for_answer);
            }
            else
            {
                answer.push_back(Character_for_answer);
                answer.push_back(map_of_punctuation[binary_version.substr(0, 2)]);
            }
        }
        
    }
    
    return answer;
}

int main () {
    std::cout << bitLetter({ 39,4,11,11,142,86,14,17,11,195 });

    return 0;
}