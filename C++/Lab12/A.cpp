#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair <int, int> nearest_number (vector <int> array_of_numbers, int to_be_found) {
    pair <int, int> result = {0, array_of_numbers[0]};
    to_be_found > 0 ? result.first = abs(array_of_numbers[0] - to_be_found) : result.first = abs(array_of_numbers[0] + to_be_found);

    for (auto &&i : array_of_numbers)
    {
        if (i == to_be_found)
        {
            return {i - to_be_found, i};
        }
        else if (abs(i - to_be_found) < result.first)
        {
            result.first = abs(i - to_be_found);
            result.second = i;
        }
    }

    return result;
}

int main () {
    int l;
    cin >> l;
    vector <int> integers(l);

    for (auto &&i : integers)
    {
        cin >> i;
    }
    
    int to_be_found;
    cin >> to_be_found;

    pair <int, int> distance_pair = nearest_number(integers, to_be_found);
    int answer = distance(integers.begin(), find(integers.begin(), integers.end(), distance_pair.second));
    cout << answer;

    return 0;
}