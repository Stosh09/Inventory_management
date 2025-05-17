#include "product.h"
#include <iostream>

Product::Product(const std::string& name, const std::string& description, int shelf_quantity, int storage_quantity, double price)
    : name(name), description(description), shelf_quantity(shelf_quantity), storage_quantity(storage_quantity), price(price) {}

void Product::printDetails() const {
    std::cout << "Product Name: " << name << "\n";
    std::cout << "Description: " << description << "\n";
    std::cout << "Shelf Quantity: " << shelf_quantity << "\n";
    std::cout << "Storage Quantity: " << storage_quantity << "\n";
    std::cout << "Price: $" << price << "\n";
}
