#include <string>
#include <vector>
#include <map>
#include <functional>


std::string function_of_return_username_1 (const std::vector<std::string> &names) {
    return names[0] + " likes this";
}

std::string function_of_return_username_2 (const std::vector<std::string> &names) {
    return names[0] + " and " + names[1] + " like this";
}

std::string function_of_return_username_3 (const std::vector<std::string> &names) {
    return names[0] + ", " + names[1] + " and " + names[2] + " like this";
}

std::string function_of_return_username_4_or_more (const std::vector<std::string> &names) {
    return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
}


std::string likes(const std::vector<std::string> &names)
{
    std:: map <int, std::function <std::string(const std::vector<std::string> &)>> answer_map = 
    {
        {1, function_of_return_username_1},
        {2, function_of_return_username_2},
        {3, function_of_return_username_3},
        {4, function_of_return_username_4_or_more},
    };
    if (names.size() > 0 && names.size() < 4)
    {
        return answer_map[(names.size())](names);
    }
    else if (names.size() >= 4)
    {
        return answer_map[4](names);
    }
    
    return "no one likes this";
}
