#include "../include/Library.h"
#include "../include/Student.h"
#include "../include/Librarian.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Library::Library() {}

Library::~Library() {
    // Clean up allocated users
    for(auto user : users) {
        delete user;
    }
    users.clear();
}

void Library::loadData() {
    std::ifstream bFile(bookFile);
    std::string line;
    if(bFile.is_open()) {
        while(getline(bFile, line)) {
            if(!line.empty())
                books.push_back(Book::fromFileString(line));
        }
        bFile.close();
    }

    std::ifstream uFile(userFile);
    if(uFile.is_open()) {
        while(getline(uFile, line)) {
            if(line.empty()) continue;
            char type = line[0];
            // Remove Type + separator (e.g., "S|")
            std::string data = line.substr(2);
            
            // Simple parsing for now
            // Data format: ID|Name|...
            size_t firstPipe = data.find('|');
            int id = std::stoi(data.substr(0, firstPipe));
            std::string rest = data.substr(firstPipe + 1);
            
            if(type == 'S') {
                size_t secondPipe = rest.find('|');
                std::string name = rest.substr(0, secondPipe);
                double fine = std::stod(rest.substr(secondPipe + 1));
                users.push_back(new Student(id, name, fine));
            } else if (type == 'L') {
                std::string name = rest;
                users.push_back(new Librarian(id, name));
            }
        }
        uFile.close();
    }
    std::cout << "Data loaded successfully.\n";
}

void Library::saveData() {
    std::ofstream bFile(bookFile);
    for(const auto& book : books) {
        bFile << book.toFileString() << "\n";
    }
    bFile.close();

    std::ofstream uFile(userFile);
    for(auto user : users) {
        uFile << user->toFileString() << "\n";
    }
    uFile.close();
    std::cout << "Data saved successfully.\n";
}

void Library::addBook(const Book& book) {
    books.push_back(book);
    std::cout << "Book added: " << book.getTitle() << "\n";
}

void Library::addUser(User* user) {
    users.push_back(user);
    std::cout << "User added: " << user->getName() << "\n";
}

void Library::listBooks() const {
    if (books.empty()) {
        std::cout << "No books in library.\n";
        return;
    }
    for(const auto& book : books) {
        book.displayDetails();
    }
}

void Library::listUsers() const {
    if (users.empty()) {
        std::cout << "No registered users.\n";
        return;
    }
    for(auto user : users) {
        user->displayRole();
    }
}

Book* Library::findBook(int id) {
    for(auto& book : books) {
        if(book.getId() == id) return &book;
    }
    return nullptr;
}

User* Library::findUser(int id) {
    for(auto user : users) {
        if(user->getId() == id) return user;
    }
    return nullptr;
}

void Library::issueBook(int userId, int bookId) {
    User* user = findUser(userId);
    Book* book = findBook(bookId);

    if(!user) { std::cout << "User not found.\n"; return; }
    if(!book) { std::cout << "Book not found.\n"; return; }
    
    if(!book->getAvailability()) {
        std::cout << "Book is already issued.\n";
        return;
    }

    book->setAvailability(false);
    std::cout << "Book '" << book->getTitle() << "' issued to " << user->getName() << ".\n";
}

void Library::returnBook(int userId, int bookId) {
    // Ideally we verify if THIS user had it, but keeping it simple
    Book* book = findBook(bookId);
    if(!book) { std::cout << "Book not found.\n"; return; }

    if(book->getAvailability()) {
        std::cout << "Book was not issued.\n";
        return;
    }

    book->setAvailability(true);
    std::cout << "Book '" << book->getTitle() << "' returned.\n";
}
