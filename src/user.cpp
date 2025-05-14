#include "user.h"
#include <iostream>

User::User(const std::string& name, const std::string& email)
    : name(name), email(email) {}

void User::display() const {
    std::cout << "User Name: " << name << "\n";
    std::cout << "Email: " << email << "\n";
}
