#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include "product.h"
#include "user.h"

class Inventory {
public:
    // Product management
    void addProduct(const Product& product);
    void displayProducts() const;

    // User management
    void addUser(const User& user);
    void displayUsers() const;
    User* findUserByEmail(const std::string& email);
    const User* findUserByEmail(const std::string& email) const;
    std::vector<User>& getUsers();
    const std::vector<User>& getUsers() const;
    bool removeUserByEmail(const std::string& email);

private:
    std::vector<Product> products;
    std::vector<User> users;
};

#endif // INVENTORY_H
