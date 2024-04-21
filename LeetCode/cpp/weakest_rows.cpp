#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
		std::vector <std::pair<int, int>> vector_pos_and_count_of_1;
		for (size_t i = 0; i < mat.size(); i++)
		{
			vector_pos_and_count_of_1.push_back(std::make_pair(i, std::count(mat[i].begin(), mat[i].end(), 1)));
		}

		std::sort(vector_pos_and_count_of_1.begin(), vector_pos_and_count_of_1.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.second == b.second ? a.first < b.second : a.first < b.first; });

		std::vector <int> result;

		for (size_t i = 0; i < k; i++)
		{
			result.push_back(vector_pos_and_count_of_1[i].first);
		}

		return result;
    }
};