class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
        {
            return 0;
        }
        
        for (int i = 1; i <= x; i++)
        {
            if ((long long)(i * i) <= x && (long long)((i + 1) * (i + 1)) > x)
            {
                return i;
            }
        }

        return 0;
    }
};