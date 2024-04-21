#include <iostream>
#include <vector>

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
    std::vector <int> copy_of_numbers = numbers;
    
    for (size_t i = 0; i < copy_of_numbers.size(); i++)
    {
        for (size_t j = i; j < copy_of_numbers.size(); j++)
        {
            if (copy_of_numbers[i] + copy_of_numbers[j] == target && i != j)
            {
                return {i, j};
            }
        }
    }
    
    return {0, 0};
}

int main () {
    std::pair <std::size_t, std::size_t> answer = two_sum({1, 2, 3}, 4);
    std::cout << answer.first << ' ' << answer.second << std::endl;
    answer = two_sum({1234, 5678, 9012}, 14690);
    std::cout << answer.first << ' ' << answer.second << std::endl;
    answer = two_sum({2, 2, 3}, 4);
    std::cout << answer.first << ' ' << answer.second << std::endl;

    return 0;
}