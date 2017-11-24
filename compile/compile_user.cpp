#include <iostream>
#include <string>
#include "compile.h"

int main() {
    std::cout << add(1, 1) << '\n';
    std::cout << add(1.5, 1.5) << '\n';
    std::cout << add(std::string{}, std::string{}) << '\n';
}