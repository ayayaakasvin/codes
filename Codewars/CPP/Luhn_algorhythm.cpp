#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

static bool validate(long long int n) {
    std::vector<int> credit_card_numbers;
    int counter = 0;
    std::string numbers = std::to_string(n);
    std::reverse(numbers.begin(), numbers.end());
    for (char c : numbers)
    {
        if (counter % 2 == 0)
        {
            credit_card_numbers.push_back(c - '0');
        }
        else if ((c - '0') * 2 > 9)
        {
            credit_card_numbers.push_back(((c - '0') * 2) % 10 + ((c - '0') * 2) / 10);
        }
        else 
        {
            credit_card_numbers.push_back((c - '0') * 2);
        }
        counter++;
    }
    int counter_1 = 0;
    for (int n : credit_card_numbers)
    {
        counter_1 += n;
    }
    
    if (counter_1 % 10 == 0)
    {
        return true;
    }

    return false;
}
