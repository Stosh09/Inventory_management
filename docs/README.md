# Inventory_management
# Inventory Management System

## Overview

The Inventory Management System is designed to manage products and users in a simple and efficient way. It allows for adding, displaying, and managing inventory items and user information.

## Project Structure

The project consists of the following main directories and files:

- **include/**: Contains header files with class declarations.
  - `inventory.h`: Declaration of the `Inventory` class.
  - `product.h`: Declaration of the `Product` class.
  - `user.h`: Declaration of the `User` class.
  - `utils.h`: Contains utility function declarations.

- **src/**: Contains the source code implementation.
  - `main.cpp`: Main entry point for the inventory management application.
  - `inventory.cpp`: Implementation of the `Inventory` class.
  - `product.cpp`: Implementation of the `Product` class.
  - `user.cpp`: Implementation of the `User` class.
  - `utils.cpp`: Implementation of utility functions.

- **tests/**: Contains test files for various components (yet to be implemented).
  - `test_inventory.cpp`: Placeholder for inventory testing.
  - `test_product.cpp`: Placeholder for product testing.
  - `test_user.cpp`: Placeholder for user testing.

## Setup and Compilation

To compile the project, you will need a C++ compiler like `g++`. Use the following command to compile and run the application:

```bash
cd src
g++ -I../include main.cpp inventory.cpp product.cpp user.cpp utils.cpp -o InventoryManagement
./InventoryManagement
```

## Usage

The Inventory Management System provides a command-line interface with the following options:

1. **Add Product**: Allows adding a new product with a name, description, quantity, and price.
2. **Add User**: Allows adding a new user with a name and email.
3. **Display Products**: Lists all products in the inventory.
4. **Display Users**: Lists all users.
5. **Exit**: Exits the application.

## Future Enhancements

- Add test cases for each component.
- Implement a persistent storage mechanism.
- Expand utility functions as needed.
- Enhance user input validation.

## Contributions

Contributions are welcome! Please fork this repository and submit pull requests for any improvements or additional features.

## License

This project is open source and available under the [MIT License](LICENSE). Feel free to use and distribute as needed.

