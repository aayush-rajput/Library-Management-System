#include "../include/Student.h"
#include <iostream>
#include <iomanip>

Student::Student(int id, std::string name, double fine) 
    : User(id, name), fineAmount(fine) {}

void Student::displayRole() const {
    displayInfo();
    std::cout << " | Fine: $" << std::fixed << std::setprecision(2) << fineAmount << std::endl;
}

void Student::addFine(double amount) {
    fineAmount += amount;
}

void Student::payFine(double amount) {
    fineAmount -= amount;
    if(fineAmount < 0) fineAmount = 0;
}

double Student::getFine() const {
    return fineAmount;
}

std::string Student::toFileString() const {
    // S|ID|Name|Fine
    return "S|" + std::to_string(id) + "|" + name + "|" + std::to_string(fineAmount);
}
