#include <iostream>

int divisors(int n){  
    int dividers = 1;
    
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            dividers++;
        }
    }
    
    return dividers;
}

int main () {
    std::cout << divisors(1) << std::endl;
    std::cout << divisors(4) << std::endl;
    std::cout << divisors(5) << std::endl;
    std::cout << divisors(12) << std::endl;
    std::cout << divisors(25) << std::endl;
    std::cout << divisors(30) << std::endl;
    std::cout << divisors(4096) << std::endl;
    
    return 0;
}