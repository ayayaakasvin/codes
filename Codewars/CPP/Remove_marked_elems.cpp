#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> remove_values(std::vector<int> integers, std::vector<int> values) {
    for (auto &&i : values)
    {
        auto it = std:: find_if(integers.begin(), integers.end(), [&](int& a){return i == a;});

        while (it != integers.end())
        {
            integers.erase(it);
            it = std:: find_if(integers.begin(), integers.end(), [&](int& a){return i == a;});
        }
    }

    return integers;
}
