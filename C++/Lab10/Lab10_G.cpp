#include <iostream>
#include <algorithm>
#include <set>
#include <vector>


int main () {
    int l;
    std:: cin >> l;
    std:: set <std:: string> participants_and_scores;

    for (int i = 0; i < l; i++)
    {
        std:: string a, b;
        int score1, score2;

        std:: cin >> a >> score1 >> b >> score2;

        std:: string particapants = a + " and " + b + ' ' + std:: to_string(score1 + score2);

        participants_and_scores.insert(particapants);
    }

    for (auto &&i : participants_and_scores)
    {
        std:: cout << i << std:: endl;
    }
    
    return 0;
} 