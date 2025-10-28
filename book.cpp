#include "book.h"
#include <sstream>

Book::Book()
    : title(), author(), isbn(), isAvailable(true), borrowerName() {}

Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerName() {}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
std::string Book::getBorrowerName() const { return borrowerName; }

void Book::setTitle(const std::string& t) { title = t; }
void Book::setAuthor(const std::string& a) { author = a; }
void Book::setISBN(const std::string& i) { isbn = i; }
void Book::setAvailability(bool available) { isAvailable = available; }
void Book::setBorrowerName(const std::string& name) { borrowerName = name; }

void Book::checkOut(const std::string& borrower) {
    isAvailable = false;
    borrowerName = borrower;
}

void Book::returnBook() {
    isAvailable = true;
    borrowerName.clear();
}

std::string Book::toString() const {
    std::ostringstream oss;
    oss  << "Titre: " << title
         << "\nAuteur: " << author
         << "\nISBN: "  << isbn
         << "\nDisponible: " << (isAvailable ? "Oui" : "Non");
    if (!isAvailable && !borrowerName.empty()) {
        oss << "\nEmprunte par: " << borrowerName;
    }
    return oss.str();
}

std::string Book::toFileFormat() const {
    std::ostringstream oss;
    oss << title << '|' << author << '|' << isbn << '|' << (isAvailable ? 1 : 0) << '|' << borrowerName;
    return oss.str();
}

void Book::fromFileFormat(const std::string& line) {
    std::istringstream iss(line);
    std::string availStr;

    std::getline(iss, title,  '|');
    std::getline(iss, author, '|');
    std::getline(iss, isbn,   '|');
    std::getline(iss, availStr, '|');
    std::getline(iss, borrowerName);

    isAvailable = (availStr == "1" || availStr == "true" || availStr == "True");
}