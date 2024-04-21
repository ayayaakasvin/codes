#include <iostream>
#include <map>
#include <set>

int main () {
    int l;
    std:: cin >> l;
    std:: map <std:: string, std:: set <int>> attendance;

    for (int i = 0; i < l; i++)
    {
        std:: string temp;
        int date;
        std:: cin >> temp >> date;
        attendance[temp].insert(date);
    }

    for (auto &&i : attendance)
    {
        if (i.second.size() >= 3)
        {
            std:: cout << i.first << ' ' << "+1" << std:: endl;
        }
        else
        {
            std:: cout << i.first << ' ' << "NO BONUS" << std:: endl;
        }
    }
    
    return 0;
}