#include <iostream>
#include "../include/Library.h"
#include "../include/Student.h"
#include "../include/Librarian.h"

void printMenu() {
    std::cout << "\n=== Library Management System ===\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Register User (Student/Librarian)\n";
    std::cout << "3. List Books\n";
    std::cout << "4. List Users\n";
    std::cout << "5. Issue Book\n";
    std::cout << "6. Return Book\n";
    std::cout << "7. Save & Exit\n";
    std::cout << "Choice: ";
}

int main() {
    Library lib;
    lib.loadData();

    int choice;
    while(true) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if(choice == 7) {
            lib.saveData();
            std::cout << "Exiting...\n";
            break;
        }

        switch(choice) {
            case 1: {
                int id;
                std::string title, author, isbn;
                std::cout << "Enter Book ID: "; std::cin >> id;
                std::cin.ignore(); 
                std::cout << "Title: "; std::getline(std::cin, title);
                std::cout << "Author: "; std::getline(std::cin, author);
                std::cout << "ISBN: "; std::getline(std::cin, isbn);
                lib.addBook(Book(id, title, author, isbn));
                break;
            }
            case 2: {
                int id;
                std::string name;
                char type;
                std::cout << "Enter User ID: "; std::cin >> id;
                std::cin.ignore();
                std::cout << "Name: "; std::getline(std::cin, name);
                std::cout << "Type (S for Student, L for Librarian): "; std::cin >> type;
                
                if(tolower(type) == 's') {
                    lib.addUser(new Student(id, name));
                } else if(tolower(type) == 'l') {
                    lib.addUser(new Librarian(id, name));
                } else {
                    std::cout << "Invalid type.\n";
                }
                break;
            }
            case 3:
                lib.listBooks();
                break;
            case 4:
                lib.listUsers();
                break;
            case 5: {
                int uid, bid;
                std::cout << "User ID: "; std::cin >> uid;
                std::cout << "Book ID: "; std::cin >> bid;
                lib.issueBook(uid, bid);
                break;
            }
            case 6: {
                int uid, bid;
                std::cout << "User ID: "; std::cin >> uid;
                std::cout << "Book ID: "; std::cin >> bid;
                // Note: user ID param not strictly used in loop for now but kept for API
                lib.returnBook(uid, bid);
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
