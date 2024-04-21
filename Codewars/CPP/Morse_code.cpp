#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <iostream>

// std::map <std::string, std::string> map_of_morse_code () {
//     std::map <std::string, std::string> returnable_map;
//     returnable_map[".-"] = 'A';
//     returnable_map["-..."] = 'B';
//     returnable_map["-.-."] = 'C';
//     returnable_map["-.."] = 'D';
//     returnable_map["."] = 'E';
//     returnable_map["..-."] = 'F';
//     returnable_map["--."] = 'G';
//     returnable_map["...."] = 'H';
//     returnable_map[".."] = 'I';
//     returnable_map[".---"] = 'J';
//     returnable_map["-.-"] = 'K';
//     returnable_map[".-.."] = 'L';
//     returnable_map["--"] = 'M';
//     returnable_map["-."] = 'N';
//     returnable_map["---"] = 'O';
//     returnable_map[".--."] = 'P';
//     returnable_map["--.-"] = 'Q';
//     returnable_map[".-."] = 'R';
//     returnable_map["..."] = 'S';
//     returnable_map["-"] = 'T';
//     returnable_map["..-"] = 'U';
//     returnable_map["...-"] = 'V';
//     returnable_map[".--"] = 'W';
//     returnable_map["-..-"] = 'X';
//     returnable_map["-.--"] = 'Y';
//     returnable_map["--.."] = 'Z';
//     returnable_map["···−−−···"] = "SOS";
//     returnable_map[" "] = " ";
// }

std::vector <std::string> tokenized_string (std::string morse_code) {
    std::string temp_string;
    std::vector <std::string> result;
    std::stringstream ss;
    
    while (getline(ss, temp_string, ' '))
    {
        result.push_back(temp_string);
    }
    
    return result;
}

// std::string decodeMorse(const std::string& morseCode) {
//     std::string decoded;
//     std::vector <std::string> morse_code_vector = tokenized_string(morseCode);
//     std::map <std::string, std::string> morse_map = map_of_morse_code();

//     for (auto &&i : morse_code_vector)
//     {
//         decoded += morse_map[i];
//     }
    
//     return decoded;
// }

// int main () {
//     std::cout << decodeMorse(".... . -.--   .--- ..- -.. .");

//     return 0;
// }

#include <string>
#include <vector>
#include <sstream>
#define MORSE_CODE


std::vector<std::string> tokenized_string(const std::string& morse_code) {
    std::vector<std::string> result;
    std::string temp;
    std::istringstream ss(morse_code);

    while (ss >> temp) {
        result.push_back(temp);
        if (ss.peek() == ' ') {
            ss.ignore();
            if (ss.peek() == ' ') {
                ss.ignore();
                result.push_back(" ");
            }
        }
    }
    return result;
}


std::string decodeMorse(const std::string& morseCode) {
    std::string decoded;
    std::vector <std::string> morse_vector = tokenized_string(morseCode);
    for( auto p : morse_vector ) {
      decoded += MORSE_CODE[p];
    }
    
    return decoded;
}