#include <string>

std::string evil(int n)
{
    std::string binary_version = "";
    while (n != 0)
    {
        binary_version.append(std::to_string(n % 2));
        n /= 2;
    }

    return count(binary_version.begin(), binary_version.end(), '1') % 2 == 0 ? "It's Evil!": "It's Odious!";
}