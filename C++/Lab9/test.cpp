#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector <int> array(n);

    for (int i = 0; i < n; i++){
        int a;
        cin >> array[i];
    }
    /*

    00 01 02 03 04
    10 11 12 13 14
    20 21 22 23 24
    30 31 32 33 34
    40 41 42 43 44

    */
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (j > i){
                cout << (array[i] ^ array[j]) << endl;
            }
        }
    }

    return 0;
}