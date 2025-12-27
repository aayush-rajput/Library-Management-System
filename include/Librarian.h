#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "User.h"

class Librarian : public User {
public:
    Librarian(int id, std::string name);

    void displayRole() const override;
    std::string getRole() const override { return "Librarian"; }

    std::string toFileString() const override;
};

#endif
