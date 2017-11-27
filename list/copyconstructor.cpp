#include "list.h"

List::List(const List& old): List{} {
    for (auto upto = old.head; upto != nullptr; upto = upto->next)
        push_back(upto->val);
}
