#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Book structure
struct Book {
    string title;
    string author;
    string isbn;
    bool available;
};

// Borrower structure
struct Borrower {
    string name;
    vector<Book*> borrowedBooks;
};

// Library class
class Library {
private:
    map<string, Book*> bookDatabase;
    map<string, Borrower*> borrowerDatabase;

public:
    // Add a book to the database
    void addBook(Book* book) {
        bookDatabase[book->isbn] = book;
    }

    // Search for a book
    Book* findBook(string isbn) {
        if (bookDatabase.count(isbn) > 0) {
            return bookDatabase[isbn];
        }
        return nullptr;
    }

    // Add a borrower
    void addBorrower(Borrower* borrower) {
        borrowerDatabase[borrower->name] = borrower;
    }

    // Check out a book
    void checkoutBook(string isbn, string borrowerName) {
        Book* book = findBook(isbn);
        if (book != nullptr && book->available) {
            Borrower* borrower = borrowerDatabase[borrowerName];
            if (borrower != nullptr) {
                borrower->borrowedBooks.push_back(book);
                book->available = false;
                cout << "Book '" << book->title << "' checked out to " << borrowerName << endl;
            } else {
                cout << "Borrower not found." << endl;
            }
        } else {
            cout << "Book not found or unavailable." << endl;
        }
    }

    // Return a book
    void returnBook(string isbn, string borrowerName) {
        Borrower* borrower = borrowerDatabase[borrowerName];
        if (borrower != nullptr) {
            for (int i = 0; i < borrower->borrowedBooks.size(); i++) {
                if (borrower->borrowedBooks[i]->isbn == isbn) {
                    borrower->borrowedBooks[i]->available = true;
                    borrower->borrowedBooks.erase(borrower->borrowedBooks.begin() + i);
                    cout << "Book '" << isbn << "' returned." << endl;
                    return;
                }
            }
            cout << "Borrower does not have this book." << endl;
        } else {
            cout << "Borrower not found." << endl;
        }
    }
    
    // Calculate a fine (placeholder, needs implementation)
    double calculateFine(string isbn, string borrowerName) {
        return 0.0; // Placeholder, add your logic here
    }

    // Print the book database
    void printBookDatabase() {
        cout << "Book Database:" << endl;
        for (auto it = bookDatabase.begin(); it != bookDatabase.end(); it++) {
            cout << "  ISBN: " << it->first << endl;
            cout << "  Title: " << it->second->title << endl;
            cout << "  Author: " << it->second->author << endl;
            cout << "  Available: " << (it->second->available ? "Yes" : "No") << endl;
        }
    }

    // Print the borrower database
    void printBorrowerDatabase() {
        cout << "Borrower Database:" << endl;
        for (auto it = borrowerDatabase.begin(); it != borrowerDatabase.end(); it++) {
            cout << "  Name: " << it->first << endl;
            cout << "  Borrowed Books:" << endl;
            for (int i = 0; i < it->second->borrowedBooks.size(); i++) {
                cout << "    " << it->second->borrowedBooks[i]->isbn << endl;
            }
        }
    }
};

int main() {
    Library library;

    // Add some books
    Book* book1 = new Book{"The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "1864113970", true};
    library.addBook(book1);
    Book* book2 = new Book{"1984", "George Orwell", "0451524934", true};
    library.addBook(book2);

    // Add some borrowers
    Borrower* borrower1 = new Borrower{"John Doe"};
    library.addBorrower(borrower1);
    Borrower* borrower2 = new Borrower{"Jane Smith"};
    library.addBorrower(borrower2);

    // Check out a book
    library.checkoutBook("1864113970", "John Doe");

    // Return a book
    library.returnBook("1864113970", "John Doe");

    // Print the databases
    library.printBookDatabase();
    library.printBorrowerDatabase();

    return 0;
}