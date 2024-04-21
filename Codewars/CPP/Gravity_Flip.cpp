#include <vector>
#include <algorithm>


std::vector<int> flip(const char dir, const std::vector<int>& arr) {
    std::vector <int> boxes = arr;
    if (dir == 'R')
    {
        std::sort(boxes.begin(), boxes.end());
    }
    else
    {
        std::sort(boxes.rbegin(), boxes.rend());
    }
    
    return boxes;
}

int main () {
    std::vector <int> lol = flip('R', {3, 2, 1, 2});
    for (int i = 0; i < lol.size(); i++)
    {
        std::cout << lol[i] << ' ';
    }

    return 0;
}
//* 'R', [3, 2, 1, 2]      ->  [1, 2, 2, 3]