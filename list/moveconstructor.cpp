#include "list.h"

List::List(List&& old): head{old.head}, tail{old.tail} {
    old.tail = nullptr;
    old.head = nullptr;
}
