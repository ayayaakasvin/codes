#include <iostream>

#include <string>

int Factorial (int n) {
    if (n == 0)
    {
        return 1;
    }
    
    return n * Factorial(n - 1);
}

std::string strong_num (int number)
{
    bool isStrong = false;
    int ValueToCompare = 0;
    int temp = number;

    for ( ; temp > 0 ; )
    {
        int digit = temp % 10;
        ValueToCompare += Factorial(digit);
        temp /= 10;
    }
    
    isStrong = ValueToCompare == number;

    return isStrong ? "STRONG!!!!" : "Not Strong !!";
}

int main () {
    std::cout << strong_num(145) << ' ' << 'T' << std::endl;
    std::cout << strong_num(1) << ' ' << 'T' << std::endl;
    std::cout << strong_num(5) << ' ' << 'F' << std::endl;
}