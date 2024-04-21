#include <math.h>
#include <iostream>

long int findNextSquare(long int sq) {
    long int rootOfNumero = sqrt(sq);
    if (rootOfNumero * rootOfNumero != sq)
    {
        return -1;
    }
    rootOfNumero++;
    return rootOfNumero * rootOfNumero;
}

int main () {
    std::cout <<  findNextSquare(144) << std::endl;
    std::cout <<  findNextSquare(169) << std::endl;
    std::cout <<  findNextSquare(89) << std::endl;
    return 0;
}