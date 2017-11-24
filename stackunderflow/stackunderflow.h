#ifndef STACKUNDERFLOW_H
#define STACKUNDERFLOW_H

#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <memory>

#include "post.h"

struct CompareByValue {
    bool operator()(const std::unique_ptr<Post> &lhs, const std::unique_ptr<Post> &rhs) const {return *lhs < *rhs;}
};

class StackUnderflow {
public:
    /*
     * Adds a post with the corresponding title and post, and adds it under each of the tags listed in tags
     */
    void addPost(const std::string& title, const std::string& post, const std::vector<std::string>& tags);

    /*
     * Removes a post so that it can no longer be accessed
     */
    void deletePost(const std::string& title);

    /*
     * Gets the post corresponding to the title
     */
    const Post* getPost(const std::string& title) const;

    /*
     * Gets all the posts tagged by tag
     */
    std::vector<Post*> getPostsByTag(const std::string& tag) const;

private:
    std::set<std::unique_ptr<Post>, CompareByValue> posts;
    std::unordered_map<std::string, std::vector<Post*>> tags;
};

#endif
