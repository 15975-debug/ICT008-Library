#pragma once

#include <iostream>
#include <string>
using namespace std;

// ==================================================
//                  AUTHOR CLASS
// ==================================================
class Author {
private:
    int id;
    string fullName;
    string country;

public:
    // Default constructor
    Author() {
        id = 0;
        fullName = "Unknown";
        country = "Unknown";
    }

    // Parameterised constructor
    Author(int i, string name, string c) {
        id = i;
        fullName = name;
        country = c;
    }

    string getName() const {
        return fullName;
    }

    void showAuthor() const {
        cout << "Author: " << fullName << endl;
        cout << "Country: " << country << endl;
    }
};

// ==================================================
//                BASE CLASS: BOOK
// ==================================================
class Book {
protected:
    string bookTitle;
    Author bookAuthor;
    string bookISBN;
    bool isAvailable;
    string addedDate;

public:
    Book(string t, Author a, string i, bool avail, string d) {
        bookTitle = t;
        bookAuthor = a;
        bookISBN = i;
        isAvailable = avail;
        addedDate = d;
    }

    virtual ~Book() {}

    virtual void showBook() {
        cout << "-----------------------------" << endl;
        cout << "Title: " << bookTitle << endl;
        cout << "Author: " << bookAuthor.getName() << endl;
        cout << "ISBN: " << bookISBN << endl;
        cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
        cout << "Date Added: " << addedDate << endl;
    }

    string getISBN() const {
        return bookISBN;
    }

    // Sorting by ISBN
    static void sortBooks(Book* arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j]->getISBN() > arr[j + 1]->getISBN()) {
                    Book* temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

// ==================================================
//           HARDCOPY BOOK CLASS
// ==================================================
class HardcopyBook : public Book {
private:
    string shelf;

public:
    HardcopyBook(string t, Author a, string i, bool avail, string d, string s)
        : Book(t, a, i, avail, d) {
        shelf = s;
    }

    void showBook() override {
        Book::showBook();
        cout << "Format: Hardcopy" << endl;
        cout << "Shelf: " << shelf << endl;
        cout << "-----------------------------" << endl;
    }
};

// ==================================================
//               EBOOK CLASS
// ==================================================
class EBook : public Book {
private:
    string expiryDate;

public:
    EBook(string t, Author a, string i, bool avail, string d, string exp)
        : Book(t, a, i, avail, d) {
        expiryDate = exp;
    }

    void showBook() override {
        Book::showBook();
        cout << "Format: EBook" << endl;
        cout << "License Expiry: " << expiryDate << endl;
        cout << "-----------------------------" << endl;
    }
};

// ==================================================
//               LIBRARY CLASS
// ==================================================
class Library {
private:
    static const int MAX = 5;
    Book* collection[MAX];

public:
    Library() {
        for (int i = 0; i < MAX; i++) {
            collection[i] = nullptr;
        }
    }

    ~Library() {
        for (int i = 0; i < MAX; i++) {
            delete collection[i];
        }
    }

    void addBook(int index, Book* b) {
        if (index >= 0 && index < MAX) {
            collection[index] = b;
        }
    }

    void sortLibrary() {
        Book::sortBooks(collection, MAX);
    }

    void displayBooks() {
        cout << "\n=== Library Books ===\n";
        for (int i = 0; i < MAX; i++) {
            if (collection[i] != nullptr) {
                collection[i]->showBook();
            }
        }
    }

    // Search by ISBN
    int findBook(string isbn) {
        for (int i = 0; i < MAX; i++) {
            if (collection[i] != nullptr && collection[i]->getISBN() == isbn) {
                return i;
            }
        }
        return -1;
    }

    // Borrow book
    void borrowBook(string isbn) {
        int index = findBook(isbn);

        if (index == -1) {
            cout << "Book not found.\n";
            return;
        }

        cout << "Borrowing book:\n";
        collection[index]->showBook();
        cout << "Book borrowed successfully.\n";
    }

    // Return book
    void returnBook(string isbn) {
        int index = findBook(isbn);

        if (index == -1) {
            cout << "Book not found.\n";
            return;
        }

        cout << "Returning book:\n";
        collection[index]->showBook();
        cout << "Book returned successfully.\n";
    }
};