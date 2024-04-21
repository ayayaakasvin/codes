#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
	std::string result;
	std::vector <int> range;

	for (size_t i = 0; i < args.size(); i++)
	{
		if (i < args.size() - 1 && abs(args[i] - args[i + 1]) == 1)
		{
			range.push_back(args[i]);
		}
		else
		{
			range.push_back(args[i]);

			
			if (range.size() >= 3)
			{
				result += std::to_string(range[0]) + '-' + std::to_string(range[range.size() - 1]) + ",";
			}
			else
			{
				for (size_t j = 0; j < range.size(); j++)
				{
					result += std::to_string(range[j]) + ",";
				}
			}

			range.clear();
		}
	}

	result.pop_back();
	
	
	return result;
}