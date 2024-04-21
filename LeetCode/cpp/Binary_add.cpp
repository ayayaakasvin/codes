#include <bitset>
#include <string>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        if (a == "0" && b == "0")
        {
            return "0";
        }
        

        std::bitset <32> binary_a(a);
        std::bitset <32> binary_b(b);
        
        std::bitset <32> answer(binary_a.to_ulong() + binary_b.to_ulong());
        std::string result = answer.to_string();
        return result.substr(result.find(1));
    }
};