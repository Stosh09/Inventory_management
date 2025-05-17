
#include "inventory.h"
#include <iostream>
#include <algorithm>

// Product management
void Inventory::addProduct(const Product& product) {
    products.push_back(product);
}

void Inventory::displayProducts() const {
    if (products.empty()) {
        std::cout << "No products in inventory." << std::endl;
        return;
    }
    std::cout << "\n--- Product List ---" << std::endl;
    for (const auto& product : products) {
        product.printDetails();
        std::cout << "--------------------" << std::endl;
    }
}

// User management
void Inventory::addUser(const User& user) {
    // Prevent duplicate emails for robustness (optional enhancement)
    for (const auto& u : users) {
        if (u.getEmail() == user.getEmail()) {
            std::cout << "User with email " << user.getEmail() << " already exists.\n";
            return;
        }
    }
    users.push_back(user);
}

void Inventory::displayUsers() const {
    if (users.empty()) {
        std::cout << "No users available." << std::endl;
        return;
    }
    std::cout << "\n--- User List ---" << std::endl;
    for (const auto& user : users) {
        user.display();
        std::cout << "--------------------" << std::endl;
    }
}

// User search/access methods
User* Inventory::findUserByEmail(const std::string& email) {
    for (auto& user : users) {
        if (user.getEmail() == email)
            return &user;
    }
    return nullptr;
}

const User* Inventory::findUserByEmail(const std::string& email) const {
    for (const auto& user : users) {
        if (user.getEmail() == email)
            return &user;
    }
    return nullptr;
}

std::vector<User>& Inventory::getUsers() {
    return users;
}

const std::vector<User>& Inventory::getUsers() const {
    return users;
}

bool Inventory::removeUserByEmail(const std::string& email) {
    auto it = std::remove_if(users.begin(), users.end(),
                             [&](const User& u) { return u.getEmail() == email; });
    if (it != users.end()) {
        users.erase(it, users.end());
        return true;
    }
    return false;
}
