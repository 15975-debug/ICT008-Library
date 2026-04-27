#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

int main() {

    Library library;
    int choice;
    string isbn;

    // Create authors
    Author a1(1, "F. Scott Fitzgerald", "American");
    Author a2(2, "Harper Lee", "American");
    Author a3(3, "George Orwell", "British");
    Author a4(4, "Jane Austen", "British");
    Author a5(5, "Herman Melville", "American");

    // Add books
    library.addBook(0, new HardcopyBook("The Great Gatsby", a1, "1001", true, "01/01/2024", "A10"));
    library.addBook(1, new HardcopyBook("To Kill a Mockingbird", a2, "1005", true, "10/01/2024", "B07"));
    library.addBook(2, new HardcopyBook("1984", a3, "1003", false, "15/01/2024", "C01"));
    library.addBook(3, new HardcopyBook("Pride and Prejudice", a4, "1002", true, "20/01/2024", "D05"));
    library.addBook(4, new EBook("Moby Dick", a5, "1004", true, "25/01/2024", "2030-12-31"));

    library.sortLibrary();

    do {
        cout << "\n===== LIBRARY MENU =====\n";
        cout << "1. Display Books\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            library.displayBooks();
        }
        else if (choice == 2) {
            cout << "Enter ISBN: ";
            cin >> isbn;
            library.borrowBook(isbn);
        }
        else if (choice == 3) {
            cout << "Enter ISBN: ";
            cin >> isbn;
            library.returnBook(isbn);
        }

    } while (choice != 0);

    return 0;
}