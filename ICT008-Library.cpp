#include <iostream>
#include "Book.h"

using namespace std;

int main() {

    // ===== Correct Books =====
    Book b1, b2, b3;

    b1.setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "1001", true, "01/01/2024");
    b2.setBookDetails("Pride and Prejudice", "Jane Austen", "1002", true, "20/01/2024");
    b3.setBookDetails("1984", "George Orwell", "1003", false, "15/01/2024");

    // ===== Incorrect Books =====
    Book b4, b5, b6;

    b4.setBookDetails("Unknown", "N/A", "ABC123", true, "32/13/2024");
    b5.setBookDetails("Test Book", "1234", "-1002", true, "99/99/9999");
    b6.setBookDetails("", "George Orwell", "1003", true, "invalid-date");

    // ===== Display Instantiation =====
    cout << "\n--- Correct Books ---\n";
    b1.displayBookDetails();
    b2.displayBookDetails();
    b3.displayBookDetails();

    cout << "\n--- Incorrect Books ---\n";
    b4.displayBookDetails();
    b5.displayBookDetails();
    b6.displayBookDetails();

    // ===== Arrays =====
    Book ascending[3] = {b1, b2, b3};
    Book descending[3] = {b3, b2, b1};
    Book mixed[3] = {b2, b1, b3};

    // ===== ASCENDING =====
    cout << "\n--- Ascending BEFORE ---\n";
    for (int i = 0; i < 3; i++) ascending[i].displayBookDetails();

    Book::sortBookData(ascending, 3);

    cout << "\n--- Ascending AFTER ---\n";
    for (int i = 0; i < 3; i++) ascending[i].displayBookDetails();

    // ===== DESCENDING =====
    cout << "\n--- Descending BEFORE ---\n";
    for (int i = 0; i < 3; i++) descending[i].displayBookDetails();

    Book::sortBookData(descending, 3);

    cout << "\n--- Descending AFTER ---\n";
    for (int i = 0; i < 3; i++) descending[i].displayBookDetails();

    // ===== MIXED =====
    cout << "\n--- Mixed BEFORE ---\n";
    for (int i = 0; i < 3; i++) mixed[i].displayBookDetails();

    Book::sortBookData(mixed, 3);

    cout << "\n--- Mixed AFTER ---\n";
    for (int i = 0; i < 3; i++) mixed[i].displayBookDetails();

    return 0;
}