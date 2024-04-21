#include <vector>
#include <algorithm>

int sumOfDifferences(const std::vector<int>& arr){
    std::vector <int> sorted_array(arr.begin(), arr.end());
    std::sort(sorted_array.begin(), sorted_array.end());


    int counter = 0;
    for (int i = sorted_array.size() - 1; i > 0; i--)
    {
        counter += sorted_array[i] - sorted_array[i - 1];
    }
    
    return counter;
}