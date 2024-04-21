#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> flip(const char dir, std::vector<int>& arr) {
    int column_height = *max_element(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr.at(i) < arr.at(i + 1))
        {
            int temp = (arr[i + 1] + arr[i]) % column_height;
            arr[i + 1] = (arr[i + 1] + arr[i]) % column_height + 1;
            arr[i] = ;
        }
        
    }
    
    return arr;
}
