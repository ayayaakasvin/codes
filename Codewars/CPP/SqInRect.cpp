#include <vector>
#include <iostream>

class SqInRect
{
    private:
        static void swapTheValues (int& length, int& width) {
            if (length < width)
            {
                std::swap(length, width);
            }
        }

        static void findAndAppendSquaresToVector (int& length, int& width, std::vector<int>& vectorOfNumeros) {
            int numberOfSquares = length / width;
            int temp = length % width;
            length = width, width = temp;

            std::vector <int> vectorToMerge(numberOfSquares, length);
            vectorOfNumeros.insert(vectorOfNumeros.end(), vectorToMerge.begin(), vectorToMerge.end());
        }

    public:
        static std::vector<int> sqInRect(int lng, int wdth){
            if (lng == wdth)
            {
                return {};
            }

            swapTheValues(lng, wdth);
            std::vector <int> squareVector = {};
            for ( ; lng > 0 && wdth > 0 ; )
            {
                findAndAppendSquaresToVector(lng, wdth, squareVector);
            }

            return squareVector;
        }
};

int main () {
    SqInRect Jokerge;
    std::vector<int> j = Jokerge.sqInRect(5, 3);
    for (std::vector<int>::iterator i = j.begin(); i != j.end(); i++)
    {
        std::cout << *i << std::endl;
    }
    
    j = Jokerge.sqInRect(3, 5);
    for (std::vector<int>::iterator i = j.begin(); i != j.end(); i++)
    {
        std::cout << *i << std::endl;
    }

    j = Jokerge.sqInRect(20, 14);
    for (std::vector<int>::iterator i = j.begin(); i != j.end(); i++)
    {
        std::cout << *i << std::endl;
    }

    return 0;
}