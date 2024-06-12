#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count_of_substring_pallindrom = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i + 1; j <= s.length(); j++)
            {
                string substring_of_s = s.substr(i, j);
                string reverse_substring_of_s(substring_of_s.rbegin(), substring_of_s.rend());
                
                if (substring_of_s == reverse_substring_of_s)
                {
                    count_of_substring_pallindrom++;
                    cout << substring_of_s << endl;
                }                
            }
        }
        
        return count_of_substring_pallindrom;
    }
};

int main () {
    Solution Jokerge;
    cout << Jokerge.countSubstrings("abc") << endl;
    cout << Jokerge.countSubstrings("aaa") << endl;
    cout << Jokerge.countSubstrings("amogus") << endl;
    cout << Jokerge.countSubstrings("rueur") << endl;
    
    return 0;
}