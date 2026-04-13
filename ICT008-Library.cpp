#include <iostream>
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
    // Set book details
    void setBookDetails(string t, string a, string i, bool avail, string d) {
        title = t;
        author = a;
        isbn = i;
        availability = avail;
        dateAdd = d;
    }

    // Display book details
    void displayBookDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Date Added: " << dateAdd << endl;
        cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
        cout << "--------------------------" << endl;
    }

    // Borrow book
    bool borrowBook() {
        if (availability) {
            availability = false;
            return true;
        }
        return false;
    }

    // Return book
    void returnBook() {
        availability = true;
    }

    // Getter for ISBN
    string getISBN() const {
        return isbn;
    }

    // Getter for availability
    bool isAvailable() const {
        return availability;
    }

    // Sort books by ISBN
    static void sortBookData(Book books[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (books[j].isbn > books[j + 1].isbn) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    const int SIZE = 5;
    Book library[SIZE];
    string inputISBN;
    bool found;
    int choice;
    char confirm;

    // Initialize 5 books
    library[0].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "1001", true, "01/01/2024");
    library[1].setBookDetails("To Kill a Mockingbird", "Harper Lee", "1005", true, "10/01/2024");
    library[2].setBookDetails("1984", "George Orwell", "1003", false, "15/01/2024");
    library[3].setBookDetails("Pride and Prejudice", "Jane Austen", "1002", true, "20/01/2024");
    library[4].setBookDetails("Moby Dick", "Herman Melville", "1004", true, "25/01/2024");

    // Sort books by ISBN
    Book::sortBookData(library, SIZE);

    cout << "===== Library Book Management System =====" << endl;

    do {
        cout << "\nBook List:" << endl;
        for (int i = 0; i < SIZE; i++) {
            library[i].displayBookDetails();
        }

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

        found = false;

        for (int i = 0; i < SIZE; i++) {
            if (library[i].getISBN() == inputISBN) {
                found = true;

                if (choice == 1) {
                    if (library[i].isAvailable()) {
                        cout << "Do you want to borrow this book? (y/n): ";
                        cin >> confirm;

                        if (confirm == 'y' || confirm == 'Y') {
                            library[i].borrowBook();
                            cout << "\nBook borrowed successfully." << endl;
                            library[i].displayBookDetails();
                        }
                        else {
                            cout << "\nBorrow cancelled." << endl;
                        }
                    }
                    else {
                        cout << "\nError: This book is currently unavailable." << endl;
                    }
                }
                else if (choice == 2) {
                    if (!library[i].isAvailable()) {
                        cout << "Do you want to return this book? (y/n): ";
                        cin >> confirm;

                        if (confirm == 'y' || confirm == 'Y') {
                            library[i].returnBook();
                            cout << "\nBook returned successfully." << endl;
                            library[i].displayBookDetails();
                        }
                        else {
                            cout << "\nReturn cancelled." << endl;
                        }
                    }
                    else {
                        cout << "\nThis book is already available in the library." << endl;
                    }
                }
                else {
                    cout << "\nInvalid menu choice." << endl;
                }

                break;
            }
        }

        if (!found) {
            cout << "\nError: Book not found." << endl;
        }

    } while (choice != 0);

    return 0;
}