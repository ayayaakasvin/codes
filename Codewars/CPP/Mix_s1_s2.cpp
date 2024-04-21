#include <string>
#include <map>
#include <iostream>

class Mix
{
public:
    static std::string mix(const std::string &s1, const std::string &s2){
		std::map <char, int> result_1, result_2;
		for (unsigned long i = 0; i < s1.length(); i++)
		{
			if ((s1.at(i) >= 'a') && (s1.at(i) <= 'z'))
			{
				result_1[s1.at(i)]++;
			}

		}

		for (unsigned long i = 0; i < s2.length(); i++)
		{
			if ((s2.at(i) >= 'a') && (s2.at(i) <= 'z'))
			{
				result_2[s2.at(i)]++;
			}
		}
		
		result_1.insert(result_2.begin(), result_2.end());
		
		for (auto &&i : result_1)
		{
			std::cout << i.second  << ':' << i.first << '/';
		}
		
		return "Jokerge";
    }
};

int main () {
		std::string s1, s2;
		s1 = "Are they here";
		s2 = "yes, they are here";
		Mix str;
		str.mix(s1, s2);

		return 0;
	}