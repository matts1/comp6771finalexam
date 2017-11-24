#ifndef BUG_H
#define BUG_H

#include <ostream>

template <typename T>
void print(std::ostream& os, T item) {
    os << item;
}

template <>
void print<const char*>(std::ostream& os, const char* string) {
    os << string << '\n';
}

template <typename T>
void print(std::ostream& os, T* ptr) {
    os << *ptr;
}

#endif
