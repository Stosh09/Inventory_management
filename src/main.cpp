#include <iostream>
#include <string>
#include "inventory.h"
#include "product.h"
#include "user.h"
#include "utils.h"

void displayMenu() {
    std::cout << "Inventory Management System\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Add User\n";
    std::cout << "3. Display Products\n";
    std::cout << "4. Display Users\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Inventory inventory;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 1) {
            std::string name, description;
            int quantity;
            double price;

            std::cout << "Enter product name: ";
            std::cin >> name;
            std::cout << "Enter product description: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            std::cout << "Enter product quantity: ";
            std::cin >> quantity;
            std::cout << "Enter product price: ";
            std::cin >> price;

            Product product(name, description, quantity, price);
            inventory.addProduct(product);
            std::cout << "Product added successfully.\n";

        } else if (choice == 2) {
            std::string name, email;

            std::cout << "Enter user name: ";
            std::cin >> name;
            std::cout << "Enter user email: ";
            std::cin >> email;

            User user(name, email);
            inventory.addUser(user);
            std::cout << "User added successfully.\n";

        } else if (choice == 3) {
            inventory.displayProducts();

        } else if (choice == 4) {
            inventory.displayUsers();

        } else if (choice == 5) {
            std::cout << "Exiting the system.\n";
            break;

        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
