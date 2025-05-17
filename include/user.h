#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& name, const std::string& email, const std::string& role = "staff");
    void display() const;

    const std::string& getName() const { return name; }
    const std::string& getEmail() const { return email; }
    const std::string& getRole() const { return role; }
    bool isAdmin() const { return role == "admin"; }

private:
    std::string name;
    std::string email;
    std::string role; // "admin" or "staff"
};

#endif // USER_H
