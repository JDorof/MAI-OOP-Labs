#include "solution.h"
#include <iostream>
#include <string>

int main () {
    std::string input;
    std::cin >> input;
    std::cout << eluminate_unset_bits(input) << std::endl;
}
