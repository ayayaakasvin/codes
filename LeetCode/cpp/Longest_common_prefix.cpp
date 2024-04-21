#include <vector>
#include <iostream>
#include <unordered_set>
#include <string>

class Solution {
public:
    int min_length_word (std::vector <std::string> words){
        int min_length = words[0].length();
        for (std::string i : words)
        {
            int length_temp = i.length();
            if (length_temp > min_length)
            {
                min_length = length_temp;
            }
        }
        
        return min_length;
    }

    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string common_prefix = "";
        std::unordered_set <char> prefix_elems;
        int length = min_length_word(strs);

        for (int i = 0; i < length;)
        {
            for (int j = 0; j < strs.size(); j++)
            {
                char chosen_character = strs[j][i];
                prefix_elems.insert(chosen_character);
            }
            if (!(prefix_elems.size() == i + 1))
            {
                break;
            }
        }

        for (char i: prefix_elems)
        {
            common_prefix += i;
        }
        
        return common_prefix;
    }
};

int main () {
    std::vector<std::string> temp = {"flower", "float", "floor"};
    Solution Jokerge;

    std::cout << Jokerge.longestCommonPrefix(temp);
    return 0;
}