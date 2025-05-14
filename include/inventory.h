#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "product.h"
#include "user.h"

class Inventory {
public:
    void addProduct(const Product& product);
    void addUser(const User& user);
    void displayProducts() const;
    void displayUsers() const;

private:
    std::vector<Product> products;
    std::vector<User> users;
};

#endif // INVENTORY_H