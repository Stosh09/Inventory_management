
#include <iostream>
#include <string>
#include "inventory.h"
#include "product.h"
#include "user.h"
#include "utils.h"

User* loginUser(Inventory& inventory) {
    std::string email;
    std::cout << "Please log in with your email: ";
    std::cin >> email;
    User* user = inventory.findUserByEmail(email);
    if (user) {
        std::cout << "Logged in as: " << user->getName() << " (" << user->getRole() << ")\n";
    } else {
        std::cout << "User not found. Please contact an admin to create your account.\n";
    }
    return user;
}

void displayMenu(const User* currentUser) {
    std::cout << "Inventory Management System\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Add User\n";
    std::cout << "3. Display Products\n";
    std::cout << "4. Display Users\n";
    std::cout << "5. Switch User\n";
    if (currentUser && currentUser->isAdmin()) {
        std::cout << "6. Remove User (admin only)\n";
    }
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Inventory inventory;
    int choice;

    // Ensure at least one admin user exists for first login
    if (inventory.getUsers().empty()) {
        std::string name, email, role = "admin";
        std::cout << "No users exist. Please create an initial admin user.\n";
        std::cout << "Enter admin name: ";
        std::cin >> name;
        std::cout << "Enter admin email: ";
        std::cin >> email;
        User admin(name, email, role);
        inventory.addUser(admin);
        std::cout << "Admin user created.\n";
    }

    User* currentUser = nullptr;
    while (!currentUser) {
        currentUser = loginUser(inventory);
    }

    while (true) {
        displayMenu(currentUser);
        std::cin >> choice;

        if (choice == 1) {
            std::string name, description;
            int shelf_quantity, storage_quantity;
            double price;

            std::cout << "Enter product name: ";
            std::cin >> name;
            std::cout << "Enter product description: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            std::cout << "Enter shelf quantity: ";
            std::cin >> shelf_quantity;
            std::cout << "Enter storage quantity: ";
            std::cin >> storage_quantity;
            std::cout << "Enter product price: ";
            std::cin >> price;

            Product product(name, description, shelf_quantity, storage_quantity, price);
            inventory.addProduct(product);
            std::cout << "Product added successfully.\n";

        } else if (choice == 2) {
            if (!currentUser->isAdmin()) {
                std::cout << "Only admins can add users.\n";
                continue;
            }
            std::string name, email, role;
            bool valid = false;

            std::cout << "Enter user name: ";
            std::cin >> name;
            std::cout << "Enter user email: ";
            std::cin >> email;

            do {
                std::cout << "Enter user role (admin/staff): ";
                std::cin >> role;
                if (role == "admin" || role == "staff") {
                    valid = true;
                } else {
                    std::cout << "Invalid role. Please enter 'admin' or 'staff'.\n";
                }
            } while (!valid);

            if (inventory.findUserByEmail(email)) {
                std::cout << "A user with that email already exists.\n";
                continue;
            }

            User user(name, email, role);
            inventory.addUser(user);
            std::cout << "User added successfully.\n";

        } else if (choice == 3) {
            inventory.displayProducts();

        } else if (choice == 4) {
            inventory.displayUsers();

        } else if (choice == 5) {
            currentUser = nullptr;
            while (!currentUser) {
                currentUser = loginUser(inventory);
            }

        } else if (choice == 6 && currentUser->isAdmin()) {
            std::string email;
            std::cout << "Enter the email of the user to remove: ";
            std::cin >> email;
            if (currentUser->getEmail() == email) {
                std::cout << "Admin users cannot remove themselves.\n";
                continue;
            }
            if (inventory.removeUserByEmail(email)) {
                std::cout << "User removed successfully.\n";
            } else {
                std::cout << "No user with that email was found.\n";
            }

        } else if (choice == 0) {
            std::cout << "Exiting the system.\n";
            break;

        } else {
            std::cout << "Invalid choice or access denied. Please try again.\n";
        }
    }

    return 0;
}
