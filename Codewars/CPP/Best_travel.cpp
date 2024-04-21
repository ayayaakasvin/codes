#include <vector>
#include <iostream>
#include <algorithm>

class BestTravel
{
public:
    static int chooseBestSum(int t, int k, std::vector<int>& ls){
        std::vector<int> best_travel_array(k);
        
        for (unsigned long i = 0; i < ls.size(); i++)
        {
            for (unsigned long j = i; j < ls.size(); j++)
            {
                best_travel_array.push_back(5);
            }
            
        }
        
    }
};
