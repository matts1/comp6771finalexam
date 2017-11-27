#ifndef BUG_H
#define BUG_H

#include <ostream>

template <typename T>
void print(std::ostream& os, T item) {
    os << item;
}

void print(std::ostream& os, const char* string) {
    os << string << '\n';
}

template <typename T>
void print(std::ostream& os, T* ptr) {
    os << *ptr;
}

#endif
