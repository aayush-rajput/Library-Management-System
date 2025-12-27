#include "../include/Book.h"
#include <iostream>
#include <sstream>
#include <vector>

Book::Book(int id, std::string title, std::string author, std::string isbn)
    : id(id), title(title), author(author), isbn(isbn), isAvailable(true) {}

int Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }

void Book::setAvailability(bool status) { isAvailable = status; }

void Book::displayDetails() const {
    std::cout << "ID: " << id << " | Title: " << title 
              << " | Author: " << author << " | ISBN: " << isbn
              << " | Available: " << (isAvailable ? "Yes" : "No") << std::endl;
}

std::string Book::toFileString() const {
    return std::to_string(id) + "|" + title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0");
}

Book Book::fromFileString(const std::string& line) {
    std::stringstream ss(line);
    std::string segment;
    std::vector<std::string> parts;

    while(std::getline(ss, segment, '|')) {
        parts.push_back(segment);
    }

    if(parts.size() < 5) return Book(); // Error handling simplified

    Book b(std::stoi(parts[0]), parts[1], parts[2], parts[3]);
    b.setAvailability(parts[4] == "1");
    return b;
}
