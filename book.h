#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool availability;
    string dateAdd;

public:
    void setBookDetails(string t, string a, string i, bool avail, string d);
    void displayBookDetails() const;
    bool borrowBook();
    void returnBook();
    string getISBN() const;
    bool isAvailable() const;

    static void sortBookData(Book books[], int size);
};

#endif