
# Inventory Management System

## Overview

This Inventory Management System is a C++ console application designed for minimarts, supermarkets, and convenience stores. It enables robust tracking and management of both products and users—including role-based access control, detailed inventory (shelves vs storage), and safe admin/staff workflows.

## Project Structure

- **include/**: C++ header files for all core classes.
  - `product.h`  — Product data model (including shelf & storage quantities)
  - `user.h`     — User model (with admin/staff roles)
  - `inventory.h`— Inventory management (with robust user/product access)
  - `utils.h`    — Utility functions (eg, string case, email validation)

- **src/**: Implementation files.
  - `main.cpp`      — Main program and menu
  - `product.cpp`   — Product class implementation
  - `user.cpp`      — User class implementation
  - `inventory.cpp` — Inventory class implementation
  - `utils.cpp`     — Utility functions

- **tests/**: Placeholder for future unit tests.
  - `test_inventory.cpp`
  - `test_product.cpp`
  - `test_user.cpp`

- **docs/**: Documentation files.
  - `README.md` (this file)
  - `design.md` (optional in-depth design notes)

## Features

- **Product Management**
  - Add products with: name, description, shelf quantity, storage quantity, price
  - Distinguish between items available for sale and in backroom/storage
  - View full product list

- **User Management**
  - Add users (admin or staff) with name, email, and role
  - Find users by email
  - Remove users (admin-only, admins cannot remove themselves)
  - Prevent duplicate users by email
  - Role-based access control (admins can add/remove users, staff cannot)

- **Authentication**
  - Login required before accessing inventory (by email lookup)
  - Users gain only the menu options permitted for their role

- **Input Validation**
  - Email format validation (basic)
  - Safe, robust main menu navigation

## Setup and Compilation

**Dependencies:**
A C++17 (or newer) compiler such as `g++` is required.

**Compile:**

```sh
g++ -Iinclude src/main.cpp src/inventory.cpp src/product.cpp src/user.cpp src/utils.cpp -o inventory_app
```

**Run:**

```sh
./inventory_app
```
*(Or `inventory_app.exe` on Windows)*

You can also feed input from a file for batch testing:
```sh
./inventory_app < test_input.txt
```

## Usage

Upon starting, the system:
- Prompts for login by email. If no users exist, requests creation of an initial admin.
- Shows a dynamic menu based on the user's role (admin or staff).
- Allows admin-only user management actions.
- Tracks and displays products and available users.

### Example Actions
- **Add User:** Admins can add both admin and staff accounts.
- **Switch User:** Log out and then back in with any registered email.
- **Add Product:** Any user can add inventory items (by business policy—customizable).
- **Remove User:** Only admins permitted.

## Future Enhancements

- Add automated tests for all functionality
- Support persistent storage (save/load inventory)
- Provide more advanced search and reporting
- Enhance input validation and error handling further
- Extend payment/product scanning logic

## Contributions

Contributions are welcome! Please fork this repository and submit pull requests for any improvements or additional features.

## License

This project is open source and available under the [MIT License](LICENSE). Feel free to use, modify, and distribute as needed.
