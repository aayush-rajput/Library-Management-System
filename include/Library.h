#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<User*> users; // Polymorphic storage
    const std::string bookFile = "data/books.txt";
    const std::string userFile = "data/users.txt";

public:
    Library();
    ~Library();

    // File Handling
    void loadData();
    void saveData();

    // Book Management
    void addBook(const Book& book);
    void listBooks() const;
    Book* findBook(int id);

    // User Management
    void addUser(User* user);
    void listUsers() const;
    User* findUser(int id);

    // Transactions
    void issueBook(int userId, int bookId);
    void returnBook(int userId, int bookId);
};

#endif
