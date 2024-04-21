#include <iostream>

long long mygcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return mygcd(b, a % b);
}

int main () {
    std::cout << mygcd(60, 12) << std::endl;
    std::cout << mygcd(1, 3) << std::endl;
    std::cout << mygcd(10927782, 6902514) << std::endl;
}