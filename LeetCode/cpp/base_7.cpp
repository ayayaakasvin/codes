#include <string>
#include <math.h>
#include <iostream>

class Solution {
public:
    std::string convertToBase7(int num) {
        int number = abs(num);
        int base_7_form_of_number = 0;

        for (int i = 0; number != 0; number /= 7, i++)
        {
            int temp = number % 7;
            base_7_form_of_number += temp * pow(10, i);
        }

        std::string answer = abs(num) == num ? std::to_string(base_7_form_of_number) : '-' + std::to_string(base_7_form_of_number);
        return answer;
    }
};

int main () {
    Solution Jokerge;
    std::cout << Jokerge.convertToBase7(-7);
    std::cout << Jokerge.convertToBase7(-7);
    std::cout << Jokerge.convertToBase7(100);
}