#ifndef COMPILE_H
#define COMPILE_H

#include <type_traits>

template <typename T>
T add(T num1, T num2) {
    // alternatively is_floating_point || is_integral
    static_assert(std::is_arithmetic<T>(), "");
    return num1 + num2;
}

#endif
