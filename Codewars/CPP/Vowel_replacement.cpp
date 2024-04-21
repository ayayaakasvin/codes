#include <string>
#include <algorithm>

using namespace std;

string replace(const string &s)
{
    string vowels = "AEUIOaeuio";
    string s_copy = s;
    for (int i = 0; i < vowels.length(); i++)
    {
        string::iterator it = find(s_copy.begin(), s_copy.end(), vowels[i]);

        while (it != s_copy.end())
        {
            s_copy.replace(distance(s_copy.begin(), it), 1, "!");
            it = find(s_copy.begin(), s_copy.end(), vowels[i]);
        }
    }
    
    return s_copy;
}