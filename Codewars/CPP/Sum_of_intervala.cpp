#include <vector>
#include <algorithm>
#include <numeric>


int sum_intervals(std::vector<std::pair<int, int>> intervals) {
    std::sort(intervals.begin(), intervals.end(), [] (const std::pair <int, int>& a, const std::pair <int, int>& b){ return a.first < b.first;});

    unsigned long i = 1;
    while (i < intervals.size())
    {
        if (intervals[i - 1].second >= intervals[i].first)
        {
            intervals[i] = std::make_pair(intervals[i - 1].first, intervals[i].second);
            intervals.erase(intervals.begin() + i - 1);
        }
        else
        {
            i++;
        }        
    }


    int counter = std::accumulate(intervals.begin(), intervals.end(), 0, [](int temp, const std::pair <int, int>& a){
            return temp + (a.second - a.first);
        });

    return counter;
}