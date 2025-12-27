#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    std::string isbn;
    bool isAvailable;

public:
    Book() : id(0), isAvailable(true) {} // Default constructor
    Book(int id, std::string title, std::string author, std::string isbn);

    // Getters and Setters (Encapsulation)
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    bool getAvailability() const;

    void setAvailability(bool status);

    // Operations
    void displayDetails() const;
    std::string toFileString() const; // For file saving
    static Book fromFileString(const std::string& line); // Factory method
};

#endif
