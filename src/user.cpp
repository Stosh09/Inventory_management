#include "user.h"
#include <iostream>

User::User(const std::string& name, const std::string& email, const std::string& role)
    : name(name), email(email), role(role) {}

void User::display() const {
    std::cout << "User Name: " << name << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Role: " << role << "\n";
}
