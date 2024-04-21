#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std:: vector <std:: pair <int, std:: vector <int>>> sorted_2d_array (std:: vector <std:: vector <int>> array_2d) {
    std:: vector <std:: pair <int, std:: vector <int>>> sorting;
    for (auto &&i : array_2d)
    {
        int sum_of_row = std:: accumulate(i.begin(), i.end(), 0);
        sorting.push_back(std:: make_pair(sum_of_row, i));
    }
    std:: sort(sorting.begin(), sorting.end(), [] (const std:: pair <int, std:: vector <int>>& a, const std:: pair <int, std:: vector <int>>& b)
     {return a.first < b.first; });
    return sorting;
}

int main () {
    int l;
    std:: cin >> l;
    std::cin.ignore();
    std:: vector <std:: vector <int>> array;


    for (int i = 0; i < l; i++)
    {
        int size_of_row;
        std:: cin >> size_of_row;
        std:: vector <int> row(size_of_row);
        for (int i = 0; i < size_of_row; i++)
        {
            std:: cin >> row[i];
        }
        
        array.push_back(row);
    }
    
    std:: vector <std:: pair <int, std:: vector <int>>> result = sorted_2d_array(array);
    
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].second.size(); j++)
        {
            std:: cout << result[i].second[j] << ' ';
        }
        std:: cout << std:: endl;
    }
    
    return 0;
}