// #include <iostream>
// #include <map>
// #include <vector>
// #include <algorithm>

// std:: vector <std:: pair <std:: string, double>> solution (std:: map <std:: string, int> students_and_scores, int overall_sum) {
//     std:: vector <std:: pair <std:: string, double>> result;
//     std:: vector <std:: pair <std:: string, double>> final_result;
//     for (auto &&i : students_and_scores)
//     {
//         std:: string student_name = i.first;
//         double percent_of_student_score = (i.second * 100) / (overall_sum * 1.0);
//         result.push_back(std:: make_pair(student_name, percent_of_student_score));
//     }

//     std:: sort(result.begin(), result.end(), [](const std:: pair <std:: string, double>& a, const std:: pair <std:: string, double>& b){return a.second > b.second;});


//     std:: vector <std:: pair <std:: string, double>> s;
//     s.push_back(result[0]);
//     for (int i = 0; i < result.size() - 1; i++)
//     {
//         if (result[i].second == result[i + 1].second)
//         {
//             s.push_back(result[i + 1]);
//         }
//         else
//         {
//             std:: sort(s.begin(), s.end(), [](const std:: pair <std:: string, double>& a, const std:: pair <std:: string, double>& b){return a.first > b.first;});
//             final_result.insert(final_result.end(), s.begin(), s.end());
//         }
//     }

//     return final_result;
// }

// int main () {
//     int l, overall_sum = 0;
//     std:: cin >> l;

//     std:: map <std:: string, int> students_and_scores;
//     for (int i = 0; i < l; i++)
//     {
//         std::string temp_name;
//         int score;
//         std::cin >> temp_name >> score;
//         students_and_scores[temp_name] += score;
//         overall_sum += score;
//     }
    
//     std:: vector <std:: pair <std:: string, double>> answer = solution(students_and_scores, overall_sum);

//     for (auto &&i : answer)
//     {
//         std:: cout << i.first << ' ' << i.second << '%' << std:: endl;
//     }

//     return 0;
// }

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::vector<std::pair<std::string, double>> solution(std::map<std::string, int> students_and_scores, int overall_sum) {
    std::vector<std::pair<std::string, double>> result;
    std::vector<std::pair<std::string, double>> final_result;

    for (auto it = students_and_scores.begin(); it != students_and_scores.end(); ++it) {
    const std::string& student_name = it->first;
    int score = it->second;
    double percent_of_student_score = (score * 100.0) / overall_sum;
    result.emplace_back(student_name, percent_of_student_score);
    }

    std::sort(result.begin(), result.end(), [](const auto& a, const auto& b) { return a.second > b.second; });

    std::vector<std::pair<std::string, double>> s;
    s.push_back(result[0]);

    for (size_t i = 0; i < result.size() - 1; ++i) {
        if (result[i].second == result[i + 1].second) {
            s.emplace_back(result[i + 1]);
        } else {
            std::sort(s.begin(), s.end(), [](const auto& a, const auto& b) { return a.first > b.first; });
            final_result.insert(final_result.end(), s.begin(), s.end());
            s.clear();
            s.push_back(result[i + 1]);
        }
    }
    std::sort(s.begin(), s.end(), [](const auto& a, const auto& b) { return a.first > b.first; });
    final_result.insert(final_result.end(), s.begin(), s.end());
    s.clear();
    s.push_back(result[result.size()]);

    return final_result;
}

int main() {
    int l, overall_sum = 0;
    std::cin >> l;

    std::map<std::string, int> students_and_scores;
    for (int i = 0; i < l; i++) {
        std::string temp_name;
        int score;
        std::cin >> temp_name >> score;
        students_and_scores[temp_name] += score;
        overall_sum += score;
    }

    std::vector<std::pair<std::string, double>> answer = solution(students_and_scores, overall_sum);

    for (const auto& i : answer) {
        std::cout << i.first << ' ' << i.second << '%' << std::endl;
    }

    return 0;
}
