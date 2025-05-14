cmake_minimum_required(VERSION 3.10)
project(InventoryManagement)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/inventory.cpp
    src/product.cpp
    src/user.cpp
    src/utils.cpp
)

# Executable
add_executable(InventoryManagement ${SOURCES})

# Link libraries (if any)
# target_link_libraries(InventoryManagement <libraries>)
