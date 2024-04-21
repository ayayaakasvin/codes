#include <iostream>
#include <map>
#include <cmath>

int quadrant(int x, int y) {
    std::map<std::pair<int, int>, int> kekq {
        {{1, 1}, 1}, {{-1, 1}, 2}, {{-1, -1}, 3}, {{1, -1}, 4}
    };
    return kekq[{x / abs(x), y / abs(y)}];
}

int main () {
    std::cout << quadrant(-10, 100);
}