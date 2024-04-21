#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

bool if_pallindram_possible (std:: vector <int> array) {
    std:: map <int, int> elements;
    for (auto &&i : array)
    {
        elements[i] += 1;
    }
    
    for (auto &&i : elements)
    {
        std:: cout << i.first << ' ' << i.second << std:: endl;
    }
    
    return true;
}

int main () {
    int l;
    std:: cin >> l;
    std:: vector <int> elements(l);
    for (auto &&i : elements)
    {
        std:: cin >> i;
    }
    
    if_pallindram_possible(elements);

    return 0;
}