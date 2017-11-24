#include "stackunderflow.h"

void StackUnderflow::addPost(const std::string& title, const std::string& body, const std::vector<std::string>& tags) {
    deletePost(title);
    auto& post = *posts.insert(std::make_unique<Post>(title, body)).first;
    for (const auto& tag : tags)
        this->tags[tag].push_back(post.get());
}

void StackUnderflow::deletePost(const std::string& title) {
    auto post = posts.find(std::make_unique<Post>(title));
    if (post != posts.end())
        posts.erase(post);
}

const Post* StackUnderflow::getPost(const std::string& title) const {
    auto post = posts.find(std::make_unique<Post>(title));
    if (post == posts.end())
        return nullptr;
    return post->get();
}

std::vector<Post*> StackUnderflow::getPostsByTag(const std::string& tag) const {
    if (tags.find(tag) == tags.end())
        return {};
    return tags.at(tag);
}
