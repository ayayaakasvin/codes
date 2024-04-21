#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int last_digit(const std::string &str1, const std::string &str2) {
    if (str2 == "0")
    {
        return 1;
    }
    
    std::string non_changable_numbers = "0156";
    if (std::find(non_changable_numbers.begin(), non_changable_numbers.end(), str1.back()) != non_changable_numbers.end())
    {
        return str1.back() - '0';
    }
    
    int number = str1.back() - '0';
    std::map <char, std::vector <int>> ints_and_their_degrees;
    ints_and_their_degrees[2] = {2, 4, 8, 6};
    ints_and_their_degrees[3] = {3, 9, 7, 1};
    ints_and_their_degrees[4] = {4, 6};
    ints_and_their_degrees[7] = {7, 9, 3, 1};
    ints_and_their_degrees[8] = {8, 4, 2, 6};
    ints_and_their_degrees[9] = {9, 1};

    int exponento = std::stoi(str2.length() > 2 ? (str2.substr(str2.length() - 2)) : str2) % ints_and_their_degrees[number].size();
    exponento = (exponento == 0 ? ints_and_their_degrees[number].size() - 1 : exponento - 1);
    int answer = ints_and_their_degrees[number][exponento];
    return answer; 
}

int main () {
    std::cout << last_digit("4", "1") << std::endl; // 4
    std::cout << last_digit("4", "2") << std::endl; // 6
    std::cout << last_digit("9", "7") << std::endl; // 9
    std::cout << last_digit("10","10000000000") << std::endl;;
    std::cout << last_digit("3715290469715693021198967285016729344580685479654510946723", "68819615221552997273737174557165657483427362207517952651") << std::endl; // 7
    std::cout << last_digit("1606938044258990275541962092341162602522202993782792835301376", "2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376") << std::endl; // 6
    
    return 0;
}