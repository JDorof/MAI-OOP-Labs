#include "solution.h"
#include <iostream>

int main () {
    Seven sev1("100000000");
    Seven sev2("1100");
    Seven sev3("11");
    Seven sev4("12000");
    // std::cout << (sev1 < sev2) << '\n';
    // std::cout << (sev1 < sev3) << '\n';
    // std::cout << (sev1 < sev4) << '\n';
    // std::cout << (sev2 < sev4) << '\n';
    std::cout << (sev2 < sev3) << (sev2 > sev3) << (sev2 == sev3) << '\n';
    // std::cout << (sev2 < sev1) << '\n';
    // std::cout << (sev3 < sev1) << '\n';
    std::cout << (sev3 < sev2) << (sev3 > sev2) << (sev3 == sev2) << '\n';
}
