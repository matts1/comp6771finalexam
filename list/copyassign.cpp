#include <utility>

#include "list.h"

List& List::operator=(const List& old) {
    List cp = old;
    std::swap(*this, cp);
    return *this;
}
