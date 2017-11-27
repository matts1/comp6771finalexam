#include "list.h"

List::~List() {
    while (head) {
        auto next = head->next;
        delete head;
        head = next; // if we just did head = next->head, we'd be accessing a deleted item
    }
}
