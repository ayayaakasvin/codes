#include <string>
#include <iostream>

class Solution {
public:
    bool halvesAreAlike(std::string s) {
        int half = s.length() / 2;
        std::string first_half = s.substr(0, half), second_half = s.substr(half, half);

        std::string vowels = "AEUIOaeuio";
        int counter_1 = 0;
        int counter_2 = 0;
        
        for (int i = 0; i < half; i++)
        {
            if (vowels.find(first_half[i]) != -1)
            {
                counter_1++;
            }
            else
            {
                counter_1--;
            }

            if (vowels.find(second_half[i]) != -1)
            {
                counter_2++;
            }
            else
            {
                counter_2--;
            }
        }

        return counter_1 == counter_2;
    }
};

int main () {
    Solution Jokerge;

    std::cout << Jokerge.halvesAreAlike("abva");

    return 0;
}