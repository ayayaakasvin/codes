#include <vector>
#include <string> 
#include <algorithm>

std::vector<std::string> sortByLength(std::vector<std::string> array) {
	std::sort(array.begin(), array.end(), [](const std::string a, const std::string b) {return a.length() < b.length(); });
	return array;
}	
