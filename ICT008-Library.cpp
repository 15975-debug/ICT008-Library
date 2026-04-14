#include <iostream>
#include <string>

using namespace std;

class Author {
private:
    string authorName;
    string nationality;

public:
    void setAuthorDetails(string name, string nation) {
        authorName = name;
        nationality = nation;
    }

    void displayAuthorDetails() const {
        cout << "Author: " << authorName << endl;
        cout << "Nationality: " << nationality << endl;
    }

    string getAuthorName() const {
        return authorName;
    }
};

class Book {
private:
    string title;
    string isbn;
    bool availability;
    string dateAdd;
    Author author;

public:
    void setBookDetails(string t, string i, bool avail, string d, Author a) {
        title = t;
        isbn = i;
        availability = avail;
        dateAdd = d;
        author = a;
    }

    void displayBookDetails() const {
        cout << "Title: " << title << endl;
        author.displayAuthorDetails();
        cout << "ISBN: " << isbn << endl;
        cout << "Date Added: " << dateAdd << endl;
        cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
        cout << "--------------------------" << endl;
    }

    bool borrowBook() {
        if (availability) {
            availability = false;
            return true;
        }
        return false;
    }

    void returnBook() {
        availability = true;
    }

    string getISBN() const {
        return isbn;
    }

    bool isAvailable() const {
        return availability;
    }
};

class Library {
private:
    Book books[5];
    int totalBooks;

public:
    void initializeBooks() {
        totalBooks = 5;

        Author author1, author2, author3, author4, author5;

        author1.setAuthorDetails("F. Scott Fitzgerald", "American");
        author2.setAuthorDetails("Harper Lee", "American");
        author3.setAuthorDetails("George Orwell", "British");
        author4.setAuthorDetails("Jane Austen", "British");
        author5.setAuthorDetails("Herman Melville", "American");

        books[0].setBookDetails("The Great Gatsby", "1001", true, "01/01/2024", author1);
        books[1].setBookDetails("To Kill a Mockingbird", "1005", true, "10/01/2024", author2);
        books[2].setBookDetails("1984", "1003", false, "15/01/2024", author3);
        books[3].setBookDetails("Pride and Prejudice", "1002", true, "20/01/2024", author4);
        books[4].setBookDetails("Moby Dick", "1004", true, "25/01/2024", author5);
    }

    void displayAllBooks() const {
        cout << "\nBook List:" << endl;
        for (int i = 0; i < totalBooks; i++) {
            books[i].displayBookDetails();
        }
    }

    int searchBookByISBN(string isbn) const {
        for (int i = 0; i < totalBooks; i++) {
            if (books[i].getISBN() == isbn) {
                return i;
            }
        }
        return -1;
    }

    void borrowBookByISBN(string isbn) {
        char confirm;
        int index = searchBookByISBN(isbn);

        if (index == -1) {
            cout << "\nError: Book not found." << endl;
            return;
        }

        if (books[index].isAvailable()) {
            cout << "Do you want to borrow this book? (y/n): ";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                books[index].borrowBook();
                cout << "\nBook borrowed successfully." << endl;
                books[index].displayBookDetails();
            }
            else {
                cout << "\nBorrow cancelled." << endl;
            }
        }
        else {
            cout << "\nError: This book is currently unavailable." << endl;
        }
    }

    void returnBookByISBN(string isbn) {
        char confirm;
        int index = searchBookByISBN(isbn);

        if (index == -1) {
            cout << "\nError: Book not found." << endl;
            return;
        }

        if (!books[index].isAvailable()) {
            cout << "Do you want to return this book? (y/n): ";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                books[index].returnBook();
                cout << "\nBook returned successfully." << endl;
                books[index].displayBookDetails();
            }
            else {
                cout << "\nReturn cancelled." << endl;
            }
        }
        else {
            cout << "\nThis book is already available in the library." << endl;
        }
    }

    void sortBookData() {
        for (int i = 0; i < totalBooks - 1; i++) {
            for (int j = 0; j < totalBooks - i - 1; j++) {
                if (books[j].getISBN() > books[j + 1].getISBN()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    Library library;
    int choice;
    string inputISBN;

    library.initializeBooks();
    library.sortBookData();

    cout << "===== Library Book Management System =====" << endl;

    do {
        library.displayAllBooks();

        cout << "\nMenu:" << endl;
        cout << "1. Borrow a book" << endl;
        cout << "2. Return a book" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Program terminated." << endl;
            break;
        }

        cout << "Enter the ISBN of the book: ";
        cin >> inputISBN;

        if (choice == 1) {
            library.borrowBookByISBN(inputISBN);
        }
        else if (choice == 2) {
            library.returnBookByISBN(inputISBN);
        }
        else {
            cout << "\nInvalid menu choice." << endl;
        }

    } while (choice != 0);

    return 0;
}