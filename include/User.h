#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

// Abstract Base Class
class User {
protected:
    int id;
    std::string name;

public:
    User(int id, std::string name);
    virtual ~User() {} // Virtual destructor

    // Pure virtual function (Abstraction)
    virtual void displayRole() const = 0;
    
    // Virtual function (Polymorphism)
    virtual std::string getRole() const { return "User"; }

    int getId() const;
    std::string getName() const;

    virtual void displayInfo() const;
    
    virtual std::string toFileString() const = 0; // Each user type saves differently
};

#endif
