#include "product.h"
#include <iostream>

Product::Product(const std::string& name, const std::string& description, int quantity, double price)
    : name(name), description(description), quantity(quantity), price(price) {}

void Product::printDetails() const {
    std::cout << "Product Name: " << name << "\n";
    std::cout << "Description: " << description << "\n";
    std::cout << "Quantity: " << quantity << "\n";
    std::cout << "Price: $" << price << "\n";
}
