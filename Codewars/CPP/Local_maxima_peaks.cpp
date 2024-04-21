#include <vector>
#include <iostream>


struct PeakData {
  std::vector<int> pos, peaks;
};


PeakData pick_peaks(const std::vector<int> &v) {
	PeakData result;

	std::vector<int> positions;
	std::vector<int> value_of_position;

	for (unsigned long i = 1; i + 1 < v.size(); i++)
	{
		if (v[i - 1] < v[i] && v[i] > v[i + 1])
		{
			positions.push_back(i);
			value_of_position.push_back(v[i]);
		}
		else if (v[i - 1] < v[i] && v[i] == v[i + 1])
		{
			unsigned long j;
			for (j = i; j + 1 < v.size() && v[j] == v[j + 1]; j++)
			{}

			if (j + 1 < v.size() && v[j] > v[j + 1]) 
			{
                positions.push_back(i);
                value_of_position.push_back(v[i]);
            }
		}
	}

	result.pos = positions;
	result.peaks = value_of_position;
	
	return result;
}

int main () {
	PeakData answer = pick_peaks({1, 2, 2});

	for (int i = 0; i < answer.pos.size(); i++)
	{
		std:: cout << answer.pos[i] << ' ';
		std:: cout << answer.peaks[i] << std::endl;
	}
	return 0;
}
