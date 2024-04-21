#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

std::vector <std::pair <std::string , int>> sorted_vector (std::vector <std::pair <std::string , int>> should_be_sorted) {
    std::vector <std::pair <std::string, int>> same_first_letter = {should_be_sorted[0]};
    std::vector <std::pair <std::string, int>> result;
    for (int i = 0; i < should_be_sorted.size() - 1; i++)
    {
        if (should_be_sorted[i].first.at(0) == should_be_sorted[i + 1].first.at(0))
        {
            same_first_letter.push_back(should_be_sorted[i + 1]);
        }
        else
        {
            std::sort(same_first_letter.begin(), same_first_letter.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
            });
            result.insert(result.end(), same_first_letter.begin(), same_first_letter.end());
            same_first_letter = {should_be_sorted[i + 1]};
        }
    }

    std::sort(same_first_letter.begin(), same_first_letter.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
            });
    result.insert(result.end(), same_first_letter.begin(), same_first_letter.end());

    return result;
}

std::vector <std::pair <std::string, int>> collected (std::vector <std::pair <std::string, int>> input) {
    std::vector <std::pair <std::string, int>> output;
    std::vector <std::pair <std::string, int>> answer;

    for (const std::pair <std::string, int> &input_unit : input)
    {
        auto it = std::find_if(output.begin(), output.end(), [&](const std::pair<std::string, int> output_unit){return input_unit.first == output_unit.first;});

        if (it == output.end())
        {
            output.push_back(input_unit);
        }
        else
        {
            it->second += input_unit.second;
        }
    }
    std::sort(output.begin(), output.end());
    answer = sorted_vector(output);

    return answer;
}

int main () {
    int l;
    std::cin >> l;
    std::vector <std::pair <std::string, int>> students_and_grades (l);
    for (std::pair <std::string, int>& i : students_and_grades)
    {
        std::string temp_name;
        int temp_grade;
        std::cin >> temp_name >> temp_grade;
        i = std::make_pair(temp_name, temp_grade);
    }


    for (auto &i : collected(students_and_grades))
    {
        std::cout << i.first << ' ' << i.second;
        std::cout << std::endl;
    }

    return 0;
}