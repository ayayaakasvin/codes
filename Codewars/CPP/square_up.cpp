#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> squareUp(int n)
{
	std::vector <int> result;
	for (size_t i = n; 0 < i; i--)
	{
		std::vector <int> temp_vector;
		for (size_t j = 0; j <= n; j++)
		{
			i >= j ? temp_vector.push_back(j) : temp_vector.push_back(0);
		}
		result.insert(result.end(), temp_vector.begin() + 1, temp_vector.end());
	}
	
	std:: reverse(result.begin(), result.end());
    return result;
}
