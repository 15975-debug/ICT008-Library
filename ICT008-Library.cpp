#include <iostream>
#include "Book.h"

using namespace std;

int main() {
    Book book1, book2, book3;

    book1.setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "1001", true, "01/01/2024");
    book2.setBookDetails("1984", "George Orwell", "1003", false, "15/01/2024");
    book3.setBookDetails("Pride and Prejudice", "Jane Austen", "1002", true, "20/01/2024");

    Book library[3] = {book1, book2, book3};

    cout << "Before sorting:\n";
    for (int i = 0; i < 3; i++) {
        library[i].displayBookDetails();
    }

    Book::sortBookData(library, 3);

    cout << "\nAfter sorting:\n";
    for (int i = 0; i < 3; i++) {
        library[i].displayBookDetails();
    }

    return 0;
}