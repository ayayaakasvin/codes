#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer_from_server (vector <pair<string, string>> database, vector <pair<string, string>> requests_from_clients) {
    vector <int> solution;
    for (pair <string, string> request : requests_from_clients)
    {
        auto it = find_if(database.begin(), database.end(), [&](pair<string, string> database_unit){return request.first == database_unit.first; });

        if (it != database.end()) 
        {
            if (it->second != request.second) 
            {
                solution.push_back(2);
            } 
            else 
            {
                solution.push_back(3);
            }
        } 
        else 
        {
            solution.push_back(1);
        }
    }

    return solution;
}

int main () {
    int l;
    cin >> l;
    vector<pair<string, string>> logins_and_passwords;
    logins_and_passwords.resize(l);
    for (int i = 0; i < l; i++)
    {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        logins_and_passwords[i] = make_pair(temp1, temp2);
    }

    cin >> l;
    vector<pair<string, string>> requests;
    requests.resize(l);  
    for (int i = 0; i < l; i++)
    {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        requests[i] = make_pair(temp1, temp2);
    }
    
    map <int, string> recall = {
        {1, "login error"}, {2, "password error"}, {3, "correct password"}
    };

    for (int i : answer_from_server(logins_and_passwords, requests))
    {
        cout << recall[i] << endl;
    }
    
    return 0;
}