#include <vector>
#include <numeric>

std::vector<int> between(int start, int end) {
    std::vector <int> result(abs(end - start) + 1);
    std::iota(result.begin(), result.end(), start);

    return result;
}  