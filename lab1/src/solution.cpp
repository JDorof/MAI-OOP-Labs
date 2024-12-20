#include <string>
#include <stdexcept>



long eluminate_unset_bits(const std::string& number) {
    if (number.empty()) throw std::invalid_argument("Input string is empty. Expected a binary string.");
    long result = 0;
    long counter = 1;
    for (const auto& c : number) {
        if (c == '1') {
            result += counter;
            counter *= 2;
        }
    }
    return result;
}