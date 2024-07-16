#include <unordered_map>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_map<int, bool> appereanceOfSums;

        while (n != 1)
        {
            n = getTheSumOfSquares(n);
            if (appereanceOfSums[n]) {
                return false;
            } else {
                appereanceOfSums[n] = true;
            }
        }

        return true;
    }

private:
    int getTheSumOfSquares (int n) {
        int result = 0;

        while (n > 0)
        {
            int square = n % 10;
            result += square * square;
            n /= 10;
        }

        return result;
    }
};