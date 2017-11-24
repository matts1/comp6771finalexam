#include "list.h"

List::iterator::reference List::iterator::operator*() {
    return n->val;
}

List::iterator& List::iterator::operator++() {
    n = n->next;
    return *this;
}

List::iterator& List::iterator::operator--() {
    if (n)
        n = n->prev;
    else
        n = list.tail;
    return *this;
}

List::iterator List::iterator::operator++(int) {
    List::iterator it = *this;
    ++*this;
    return it;
}

List::iterator List::iterator::operator--(int) {
    List::iterator it = *this;
    --*this;
    return it;
}

bool operator==(const List::iterator& lhs, const List::iterator& rhs) {
    return lhs.n == rhs.n;
}

bool operator!=(const List::iterator& lhs, const List::iterator& rhs) {
    return !(lhs == rhs);
}

void List::push_back(int val) {
    auto node = new Node{val};
    if (!tail)
        head = tail = node;
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

void List::push_front(int val) {
    auto node = new Node{val};
    if (!head)
        head = tail = node;
    else {
        head->prev = node;
        node->next = head;
        head = node;
    }
}
