#ifndef POST_H
#define POST_H

#include <string>

class Post {
public:
    Post(const std::string& title, const std::string& body=""): title{title}, body{body} {}
    const std::string& getTitle() const { return title; }
    const std::string& getBody() const { return body; }

    bool operator<(const Post& p) const {
        return getTitle() < p.getTitle();
    }


private:
    std::string title;
    std::string body;
};

#endif
