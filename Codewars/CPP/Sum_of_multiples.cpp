#include <numeric>
#include <vector>
#include <algorithm>

int solution(int number) 
{
    if (number == 0)
    {
        return 0;
    }
    
    std::vector<int> numbers_until(number);
    std::iota(numbers_until.begin(), numbers_until.end(), 0);
    long long int answer = std::accumulate(numbers_until.begin(), numbers_until.end(), 0, [](int summery, int k){return summery + (k % 3 == 0 || k % 5 == 0 ? k : 0);});
    return answer;

    // for (int i = 0; i < number; i++)
    // {
    //     if (i % 5 == 0 || i % 3 == 0)
    //     {
    //         answer += i;
    //     }
    // }
}   