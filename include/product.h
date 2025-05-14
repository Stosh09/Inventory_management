#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product(const std::string& name, const std::string& description, int quantity, double price);
    void printDetails() const;

private:
    std::string name;
    std::string description;
    int quantity;
    double price;
};

#endif // PRODUCT_H