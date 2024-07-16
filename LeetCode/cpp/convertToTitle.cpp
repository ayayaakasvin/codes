#include <string>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string result;
        while (columnNumber > 0)
        {
            result = getTheBase_26(columnNumber) + result;
        }
        
        return result;
    }

private:
    char getTheBase_26 (int& numero) {
        int resultInt = (numero - 1) % 26;
        numero = (numero - 1) / 26;
        
        return resultInt + 'A';
    }
};