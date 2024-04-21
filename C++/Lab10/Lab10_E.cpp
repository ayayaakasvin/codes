#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map <string, double> percentage_for_cities (unordered_map <string, int> input_vector_of_cities_and_amount) {
    int sum_of_students = 0;
    for (auto &&i : input_vector_of_cities_and_amount)
    {
        sum_of_students += input_vector_of_cities_and_amount[i.first];
    }

    unordered_map <string, double> cities_and_percentage;
    
    for (const auto &i : input_vector_of_cities_and_amount) 
    {
        double temp = (i.second * 100.0) / sum_of_students;
        cities_and_percentage[i.first] = temp;
    }

    return cities_and_percentage;
    
}

int main () {
    int l;  
    std:: cin >> l;
    unordered_map <string, int> cities_and_amount;
    for (int i = 0; i < l; i++)
    {
        int temp;
        cin >> temp;
        for (int i = 0; i < temp; i++)
        {
            string city;
            int amount;
            cin >> city >> amount;
            cities_and_amount[city] += amount;
        }
    }

    unordered_map <string, double> cities_and_persentage = percentage_for_cities(cities_and_amount);
    vector <string> key_for_map;
    for (auto &&i : cities_and_persentage)
    {
        key_for_map.push_back(i.first);
    }
    
    sort(key_for_map.begin(), key_for_map.end());
    
    for (auto &&i : key_for_map)
    {
        cout << i << ' ' << cities_and_persentage[i] << endl;
    }
    
    return 0;
}
// ====== Test #9 =======
// --- Input: size 728 ---
// 5
// 12
// Oral 232
// PetroPavlsk 61
// Pavlodar 234
// Taraz 150
// Shymkent 34
// Merki 205
// Shymkent 190
// Merki 203
// Turkistan 68
// Pavlodar 71
// Pavlodar 119
// Astana 200
// 7
// Turkistan 135
// Astana 48
// Taraz 209
// KyzylOrda 248
// Taraz 200
// Merki 31
// Aktobe 202
// 18
// Pavlodar 165
// Aktobe 181
// KyzylOrda 149
// Pavlodar 228
// KyzylOrda 229
// PetroPavlsk 162
// Astana 128
// Oskemen 63
// Turkistan 18
// Pavlodar 66
// PetroPavlsk 173
// Aktobe 157
// Karagandy 142
// Pavlodar 87
// Aktobe 114
// Taraz 238
// Aktau 83
// Oskemen 185
// 18
// Karagandy 174
// Oskemen 65
// Oral 61
// Aktobe 65
// Kostanai 97
// Merki 234
// Kostanai 89
// Turkistan 133
// KyzylOrda 79
// Kostanai 189
// Turkistan 221
// Oral 34
// Pavlodar 71
// Aktau 172
// Aktau 235
// Oskemen 212
// Merki 42
// Taraz 90
// 6
// Taraz 58
// KyzylOrda 66
// Kostanai 178
// Almaty 229
// Astana 42
// Karagandy 142

// --- Output: size 240 ---
// Aktau 5.84307
// Aktobe 8.57381
// Almaty 2.73074
// Astana 4.9845
// Karagandy 5.46148
// Kostanai 6.59432
// KyzylOrda 9.19389
// Merki 8.52612
// Oral 3.89936
// Oskemen 6.26043
// Pavlodar 12.4135
// PetroPavlsk 4.72216
// Shymkent 2.67112
// Taraz 11.2688
// Turkistan 6.85667

// --- Correct: size 240 ---
// Aktau 5.84307
// Aktobe 8.57381
// Almaty 2.73074
// Astana 4.9845
// Karagandy 5.46148
// Kostanai 6.59432
// KyzylOrda 9.19389
// Merki 8.52611
// Oral 3.89936
// Oskemen 6.26043
// Pavlodar 12.4135
// PetroPavlsk 4.72216
// Shymkent 2.67112
// Taraz 11.2688
// Turkistan 6.85667

// --- Stderr: size 0 ---

// --- Checker output: size 82 ---
// wrong answer 8th lines differ - expected: 'Merki 8.52611', found: 'Merki 8.52612'