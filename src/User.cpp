#include "../include/User.h"
#include <iostream>

User::User(int id, std::string name) : id(id), name(name) {}

int User::getId() const { return id; }
std::string User::getName() const { return name; }

void User::displayInfo() const {
    std::cout << "ID: " << id << " | Name: " << name << " | Role: " << getRole();
}
