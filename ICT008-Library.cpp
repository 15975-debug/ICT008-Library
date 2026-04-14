#include <iostream>
#include <string>

using namespace std;

// Parent class
class Book {
protected:
    string title;
    string author;
    string isbn;
    bool availability;
    string dateAdd;

public:
    Book() {
        title = "";
        author = "";
        isbn = "";
        availability = true;
        dateAdd = "";
    }

    virtual ~Book() {
    }

    void setBookDetails(string t, string a, string i, bool avail, string d) {
        title = t;
        author = a;
        isbn = i;
        availability = avail;
        dateAdd = d;
    }

    virtual void displayBookDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Date Added: " << dateAdd << endl;
        cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
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

    virtual string getBookType() const = 0;

    static void sortBookData(Book* books[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (books[j]->getISBN() > books[j + 1]->getISBN()) {
                    Book* temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
};

// Child class for hardcopy books
class HardcopyBook : public Book {
private:
    string shelfNumber;

public:
    void setShelfNumber(string shelf) {
        shelfNumber = shelf;
    }

    void displayBookDetails() const override {
        cout << "Book Type: Hardcopy Book" << endl;
        Book::displayBookDetails();
        cout << "Shelf Number: " << shelfNumber << endl;
        cout << "--------------------------" << endl;
    }

    string getBookType() const override {
        return "Hardcopy Book";
    }
};

// Child class for e-books
class EBook : public Book {
private:
    string endOfLicenseDate;

public:
    void setLicenseDate(string date) {
        endOfLicenseDate = date;
    }

    void displayBookDetails() const override {
        cout << "Book Type: E-Book" << endl;
        Book::displayBookDetails();
        cout << "End of License Date: " << endOfLicenseDate << endl;
        cout << "--------------------------" << endl;
    }

    string getBookType() const override {
        return "E-Book";
    }
};

// Function to find a book by ISBN
int findBookByISBN(Book* books[], int size, string isbn) {
    for (int i = 0; i < size; i++) {
        if (books[i]->getISBN() == isbn) {
            return i;
        }
    }
    return -1;
}

int main() {
    const int SIZE = 5;
    Book* library[SIZE];
    int choice;
    string inputISBN;

    // Create hardcopy books
    library[0] = new HardcopyBook();
    library[1] = new HardcopyBook();
    library[2] = new HardcopyBook();

    // Create e-books
    library[3] = new EBook();
    library[4] = new EBook();

    // Set hardcopy book details
    ((HardcopyBook*)library[0])->setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "1003", true, "01/01/2024");
    ((HardcopyBook*)library[0])->setShelfNumber("A12");

    ((HardcopyBook*)library[1])->setBookDetails("To Kill a Mockingbird", "Harper Lee", "1001", true, "05/01/2024");
    ((HardcopyBook*)library[1])->setShelfNumber("B05");

    ((HardcopyBook*)library[2])->setBookDetails("1984", "George Orwell", "1005", false, "10/01/2024");
    ((HardcopyBook*)library[2])->setShelfNumber("C08");

    // Set e-book details
    ((EBook*)library[3])->setBookDetails("Digital Marketing Basics", "John Smith", "1002", true, "15/01/2024");
    ((EBook*)library[3])->setLicenseDate("15/01/2027");

    ((EBook*)library[4])->setBookDetails("C++ Programming Guide", "Jane Brown", "1004", true, "20/01/2024");
    ((EBook*)library[4])->setLicenseDate("20/01/2028");

    // Sort books by ISBN
    Book::sortBookData(library, SIZE);

    do {
        cout << "\n===== Library Management System - Phase 2 =====" << endl;
        cout << "1. Display all books" << endl;
        cout << "2. Borrow a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nLibrary Book List:" << endl;
            for (int i = 0; i < SIZE; i++) {
                library[i]->displayBookDetails();
            }
            break;

        case 2: {
            cout << "\nEnter ISBN of the book you want to borrow: ";
            cin >> inputISBN;

            int index = findBookByISBN(library, SIZE, inputISBN);

            if (index == -1) {
                cout << "Error: Book not found." << endl;
            }
            else {
                if (library[index]->borrowBook()) {
                    cout << "Book borrowed successfully." << endl;
                    library[index]->displayBookDetails();
                }
                else {
                    cout << "Error: This book is currently unavailable." << endl;
                }
            }
            break;
        }

        case 3: {
            cout << "\nEnter ISBN of the book you want to return: ";
            cin >> inputISBN;

            int index = findBookByISBN(library, SIZE, inputISBN);

            if (index == -1) {
                cout << "Error: Book not found." << endl;
            }
            else {
                library[index]->returnBook();
                cout << "Book returned successfully." << endl;
                library[index]->displayBookDetails();
            }
            break;
        }

        case 0:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    // Free memory
    for (int i = 0; i < SIZE; i++) {
        delete library[i];
    }

    return 0;
}