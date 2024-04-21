#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void binary_version_print(int decimal_to_binary) {
        std:: string binary = "";
        while (decimal_to_binary != 0)
        {
            binary.append(std::to_string(decimal_to_binary % 2));
            decimal_to_binary /= 2;
        }
        std:: reverse(binary.begin(), binary.end());
        std:: cout << binary << std:: endl;
}

int main () {
    int l;
    std:: cin >> l;

    std:: vector <int> decimal(l);

    for (int i = 0; i < l; i++)
    {
        std:: cin >> decimal[i];
    }
    
    std:: for_each(decimal.begin(), decimal.end(), binary_version_print);
}