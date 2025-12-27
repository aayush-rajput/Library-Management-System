#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"

class Student : public User {
private:
    double fineAmount;

public:
    Student(int id, std::string name, double fine = 0.0);
    
    void displayRole() const override;
    std::string getRole() const override { return "Student"; }
    
    // Student specific
    void addFine(double amount);
    void payFine(double amount);
    double getFine() const;

    std::string toFileString() const override;
};

#endif
