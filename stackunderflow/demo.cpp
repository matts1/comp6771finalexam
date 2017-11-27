#include <iostream>

#include "stackunderflow.h"

int main() {
    StackUnderflow s;
    s.addPost("hello", "world", {"a"});
    s.deletePost("hello");
    for (const auto& post : s.getPostsByTag("a")) {
        std::cout << post->getTitle() << '\n';
    }
}
