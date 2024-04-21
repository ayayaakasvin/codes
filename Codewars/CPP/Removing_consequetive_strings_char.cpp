#include <vector>
#include <string>
#include <algorithm>

std::string say_no_to_consequtive_strings (std::string input) {
    for (int i = 1; i < input.length() - 1; i++)
    {
        if (input[i] == input[i + 1] || input[i] == input[i - 1])
        {
            input.erase(input.begin() + i);
            i--;
        }
    }
    
    return input;
}

std::vector<std::string> dup(std::vector<std::string> arr){
    std::for_each(arr.begin(), arr.end(), [](std::string& s) {s = say_no_to_consequtive_strings(s);});

    return arr;
}
