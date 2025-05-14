#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& name, const std::string& email);
    void display() const;

private:
    std::string name;
    std::string email;
};

#endif // USER_H