#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <iterator>

class List {
private:
    struct Node {
        Node(const int& val): val{val} {}

        int val;
        Node* next = nullptr;
        Node* prev = nullptr;

        ~Node() {
            std::cout << "destructed\n";
            prev = nullptr;
            next = nullptr;
        }
    };

public:
    List() = default;
    List(const List&);
    List(List&&);
    List& operator=(const List&);
    List& operator=(List&&);
    ~List();

    friend class iterator;
    class iterator {
    private:
        friend class List;
        iterator(List& list, Node* n=nullptr): list{list}, n{n} {}

    public:
        using difference_type = int;
        using value_type = int;
        using pointer = int*;
        using reference = int&;
        using iterator_category = std::bidirectional_iterator_tag;

        reference operator*();
        iterator& operator++();
        iterator& operator--();
        iterator operator++(int);
        iterator operator--(int);

        friend bool operator==(const iterator& lhs, const iterator& rhs);

    private:
        List& list;
        typename List::Node* n;
    };

    void push_back(int val);
    void push_front(int val);

    iterator begin() { return iterator{*this, head}; }
    iterator end() { return iterator{*this}; }

private:
    Node* head = nullptr;
    Node* tail = nullptr;
};

bool operator!=(const typename List::iterator&, const typename List::iterator&);

#endif
