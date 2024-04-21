#include <vector>
#include <algorithm>

std::vector<unsigned int> removeSmallest(const std::vector<unsigned int>& numbers) {
    if (numbers.size() < 1)
    {
        return {};
    }
    
    std::vector <unsigned int> copy_of_const(numbers.begin(), numbers.end());
    std::vector <unsigned int> :: iterator min_value = std::min_element(copy_of_const.begin(), copy_of_const.end());

    copy_of_const.erase(min_value);
    
    return copy_of_const;
}
