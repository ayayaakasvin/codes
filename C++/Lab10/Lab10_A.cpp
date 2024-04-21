#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

std::vector <std::pair <std::string, int>> collected (std::vector <int> input_grades, std::vector <std::string> input_names) {
    std::vector <std::pair <std::string, int>> output;
    std::vector <std::pair <std::string, int>> result;

    std::sort(input_names.begin(), input_names.end());
    std::sort(input_grades.begin(), input_grades.end());

    for (int i = 0; i < input_grades.size(); i++)
    {
        output.push_back(std::make_pair(input_names.at(i), input_grades.at(i)));
    }

    return output;
}

int main () {
    int l;
    std::cin >> l;
    std::vector  <std::string> students (l);
    std::vector  <int> grades (l);
    for (int i = 0; i < l; i++)
    {
        std::string temp_name;
        int temp_grade;
        std::cin >> temp_name >> temp_grade;
        students[i] = temp_name, grades[i] = temp_grade;
    }

    for (auto &&i : collected(grades, students))
    {
        std::cout << i.first << ' ' << i.second << std::endl;
    }
    

    return 0;
}