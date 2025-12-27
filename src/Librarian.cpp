#include "../include/Librarian.h"
#include <iostream>

Librarian::Librarian(int id, std::string name) : User(id, name) {}

void Librarian::displayRole() const {
    displayInfo();
    std::cout << " | [ADMIN]" << std::endl;
}

std::string Librarian::toFileString() const {
    // L|ID|Name
    return "L|" + std::to_string(id) + "|" + name;
}
