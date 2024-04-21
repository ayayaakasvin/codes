#include <iostream>
#include <algorithm>
#include <vector>

std:: string is_stack_empty (std:: string number) {
    const std:: vector <std:: string> double_squares = {"16", "25", "36", "49", "64", "81"};
    
    for (int j = 0; j < number.length(); j++)
    {   
        for (int i = 0; i < double_squares.size(); i++)
        {
            auto it = number.find(double_squares[i]);
            while (it != std::string::npos)
            {
                number.erase(it, 2);
                it = number.find(double_squares[i]);
            }
        }
    }
    // 181649333666
    return number;
}

int main () {
    std:: string number, result;
    std:: cin >> number;

    result = is_stack_empty(number);
    if (!result.empty())
    {
        std:: reverse(result.begin(), result.end());
        std:: cout << result;
    }
    else 
    {
        std:: cout << "Stack is empty";
    }
    
    return 0;
}