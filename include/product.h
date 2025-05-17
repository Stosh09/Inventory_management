#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product(const std::string& name, const std::string& description, int shelf_quantity, int storage_quantity, double price);
    void printDetails() const;

private:
    std::string name;
    std::string description;
    int shelf_quantity;      // Quantity available on the shelf
    int storage_quantity;    // Quantity in storage/backroom
    double price;
};

#endif // PRODUCT_H
