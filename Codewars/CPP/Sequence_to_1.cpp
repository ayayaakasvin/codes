#include <vector>
#include <algorithm>

std::vector<int> seqToOne(int n) {
    std::vector <int> result;   


    if (n > 1)
    {
        result.resize(n);
        std::generate(result.begin(), result.end(), [n] () mutable  {return n--;});
    }
    else
    {
        result.resize(abs(n - 2)), std::generate(result.begin(), result.end(), [n] () mutable  {return n++;});
    }


    return result;
}