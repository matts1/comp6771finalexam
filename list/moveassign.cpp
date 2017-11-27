#include <utility>

#include "list.h"

List& List::operator=(List&& old) {
    List tmp = std::move(*this);
    head = old.head;
    tail = old.tail;
    old.head = nullptr;
    old.tail = nullptr;
    return *this;
}
