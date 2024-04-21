#include <string>
#include <iostream>
#include <iomanip>

float Serie (int n) {
    return (1.0 / (1 + 3 * n));
}

std::string fixedFloat (float target) {
    if ((int)(target * 1000) % 10 > 4)
    {
        target += 0.01;
    }
    

    std::string strVersionOfNumero = std::to_string(target);
    strVersionOfNumero = strVersionOfNumero.substr(0, strVersionOfNumero.find('.') + 3);
    return strVersionOfNumero;
}

std::string seriesSum(int n)
{
    float sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += Serie(i);
    }

    return fixedFloat(sum);
}

int main () {


    std::cout << seriesSum(1) << ' ' << 1 << std::endl;
    std::cout << seriesSum(2) << ' ' << 1.25 << std::endl;
    std::cout << seriesSum(3) << ' ' << 1.39 << std::endl;
    
    return 0;
}