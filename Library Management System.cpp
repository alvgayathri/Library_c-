#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int id;

public:
    Book(int bookId, string bookTitle, string bookAuthor) : id(bookId), title(bookTitle), author(bookAuthor) {}

    void displayDetails() {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl;
    }

    string getTitle() { return title; }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        cout << "All Books in the Library:\n";
        for (size_t i = 0; i < books.size(); ++i) {
            books[i].displayDetails();
        }
    }

    void searchBook(string title) {
        bool found = false;
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].getTitle() == title) {
                cout << "Book Found:\n";
                books[i].displayDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found!\n";
        }
    }
};

int main() {
    Library library;
    int choice, id;
    string title, author;

    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add Book\n2. Display Books\n3. Search Book\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                library.addBook(id, title, author);
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                cout << "Enter Book Title to Search: ";
                cin.ignore();
                getline(cin, title);
                library.searchBook(title);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
