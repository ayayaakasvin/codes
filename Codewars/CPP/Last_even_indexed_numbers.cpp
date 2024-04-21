#include <vector>

std::vector<int> evenNumbers(std::vector<int> arr, int n) {
    std::vector <int> result(n);

    for (int i = arr.size() - 1, j = n - 1; j >= 0 ; i--)
    {
        if (arr[i] % 2 == 0)
        {
            result[j] = arr[i];
            j--;
        }
    }

    return result;
}
