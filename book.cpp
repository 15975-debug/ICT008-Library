#include <iostream>
#include "Book.h"

using namespace std;

void Book::setBookDetails(string t, string a, string i, bool avail, string d) {
    title = t;
    author = a;
    isbn = i;
    availability = avail;
    dateAdd = d;
}

void Book::displayBookDetails() const {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Date Added: " << dateAdd << endl;
    cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
    cout << "--------------------------" << endl;
}

string Book::getISBN() const {
    return isbn;
}

void Book::sortBookData(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].getISBN() > books[j + 1].getISBN()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}