#include <iostream>
#include "classes.h"

using namespace std;

int main() {

    // =====================================================
    // CREATE AUTHORS
    // =====================================================
    Author a1(1, "F. Scott Fitzgerald", "American");
    Author a2(2, "Jane Austen", "British");
    Author a3(3, "George Orwell", "British");

    // =====================================================
    // CORRECT BOOK INITIALISATION
    // =====================================================
    cout << "===== CORRECT BOOKS =====\n";

    Book* book1 = new HardcopyBook("The Great Gatsby", a1, "1001", true, "01/01/2024", "A10");
    Book* book2 = new EBook("Pride and Prejudice", a2, "1002", true, "20/01/2024", "2030-12-31");
    Book* book3 = new HardcopyBook("1984", a3, "1003", false, "15/01/2024", "B07");

    book1->showBook();
    book2->showBook();
    book3->showBook();

    // =====================================================
    // INCORRECT BOOK INITIALISATION (1 error each)
    // =====================================================
    cout << "\n===== INCORRECT BOOKS =====\n";

    Book* wrong1 = new HardcopyBook("The Great Gatsby", a1, "ABC123", true, "01/01/2024", "A10"); // invalid ISBN
    Book* wrong2 = new EBook("Pride and Prejudice", a2, "1002", true, "2024/01/20", "2030-12-31"); // wrong date
    Book* wrong3 = new HardcopyBook("", a3, "1003", true, "15/01/2024", "B07"); // missing title

    wrong1->showBook();
    wrong2->showBook();
    wrong3->showBook();

    // =====================================================
    // SORTING TEST - ASCENDING
    // =====================================================
    cout << "\n===== SORTING (ASCENDING) =====\n";

    Book* asc[3] = { book3, book1, book2 };

    cout << "\n-- BEFORE SORT --\n";
    for (int i = 0; i < 3; i++)
        asc[i]->showBook();

    Book::sortBooks(asc, 3);

    cout << "\n-- AFTER SORT --\n";
    for (int i = 0; i < 3; i++)
        asc[i]->showBook();

    // =====================================================
    // SORTING TEST - DESCENDING
    // =====================================================
    cout << "\n===== SORTING (DESCENDING) =====\n";

    Book* desc[3] = { book1, book2, book3 };

    cout << "\n-- BEFORE SORT --\n";
    for (int i = 0; i < 3; i++)
        desc[i]->showBook();

    Book::sortBooks(desc, 3);

    // Reverse order
    swap(desc[0], desc[2]);

    cout << "\n-- AFTER SORT --\n";
    for (int i = 0; i < 3; i++)
        desc[i]->showBook();

    return 0;
}