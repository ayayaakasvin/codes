#include <string>

int any_odd(unsigned x) {
    std::string bits;

    while (x != 0)
    {
        bits += std::to_string(x % 2);
        x = x / 2;
    }
    
    for (size_t i = 0; i < bits.length(); i++)
    {
        if (bits[i] == '1' && i % 2 == 1)
        {
            return true;
        }
    }
        
    return false;
}