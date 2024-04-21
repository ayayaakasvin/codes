#include <string>
#include <vector>

std::vector<int> digitize(const int& n) {
    std::string str_n = std::to_string(n);
    std::vector <int> result;
    for (int i : str_n)
    {
        result.push_back(i - '0');
    }
    
    return result;
}