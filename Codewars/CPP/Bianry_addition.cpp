#include <cstdint>
#include <string>
#include <bitset>

std::string add_binary(uint64_t a, uint64_t b) {
    std::bitset <512> binary_version(a + b);
    std::string result = binary_version.to_string();
    result = result.substr(result.find('1'));

    return result;
}