#include <iostream>
#include <algorithm>

bool is_jojo_reference (std:: string jojo_reference_string) {
    for (int i = 0; i < jojo_reference_string.length(); i++)
    {
        std:: string s = "";
        for (int j = i; j < jojo_reference_string.length(); j++)
        {
            s.push_back(jojo_reference_string[j]);
            if (s.length() > 1)
            {
                std::string reverse_s(s.rbegin(), s.rend());
                if (reverse_s == s)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main () {
    std:: string some_string;
    std:: cin >> some_string;

    is_jojo_reference(some_string) ? std:: cout << "ZA WARUDO TOKI WO TOMARE" :
                                    std:: cout << "JOJO";
    return 0;
}