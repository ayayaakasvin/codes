#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

int find_even_index(const vector <int> numbers) {
	for (size_t i = 0; i < numbers.size(); i++)
	{
		vector <int> arr1(numbers.begin(), numbers.begin() + i);
		vector <int> arr2(numbers.begin() + i + 1, numbers.end());
		if (accumulate(arr1.begin(), arr1.end(), 0) == accumulate(arr2.begin(), arr2.end(), 0))
		{
			return i;
		}
	}
	return -1;
}
int main() {
	vector <int> input = {1, 2, 3, 4, 3, 2, 1};
	cout << find_even_index(input);
}