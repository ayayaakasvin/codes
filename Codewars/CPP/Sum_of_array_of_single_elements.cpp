#include <vector>
#include <map>
#include <numeric>

int repeats(std::vector<int>v){
    std::map <int, int> element_occur;

    for (int i = 0; i < v.size(); i++)
    {
        element_occur[v[i]]++;
    }
    
    int sum_of_elements = std::accumulate(element_occur.begin(), element_occur.end(), 0, [] (int& sum, const std::pair <int, int>& a) {return sum + (a.second == 1 ? a.first : 0);});
    
    return sum_of_elements;
}