#ifndef PUSH_MANY_BACK_H
#define PUSH_MANY_BACK_H

#include <utility>

template <typename Cont>
void push_many_back(const Cont&) {
}

template <typename Cont, typename T, typename... Ts>
void push_many_back(Cont& cont, T&& head, Ts&&... tail) {
    cont.push_back(std::forward<T>(head));
    push_many_back(cont, std::forward<Ts>(tail)...);
};

#endif
