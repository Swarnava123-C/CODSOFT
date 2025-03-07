#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Structure to represent a book
struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
    
    Book(string t, string a, string i) : title(t), author(a), ISBN(i), isAvailable(true) {}
};

// Structure to represent a borrower
struct Borrower {
    string name;
    string borrowedISBN;
    time_t borrowDate;

    Borrower(string n, string isbn) : name(n), borrowedISBN(isbn) {
        time(&borrowDate);
    }
};

// Vector to store books and borrowers
vector<Book> books;
vector<Borrower> borrowers;

// Function to add a new book
void addBook() {
    string title, author, ISBN;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter Author Name: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    getline(cin, ISBN);

    books.push_back(Book(title, author, ISBN));
    cout << "Book added successfully!\n";
}

// Function to search for a book
void searchBook() {
    string keyword;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, keyword);
    
    bool found = false;
    for (const auto& book : books) {
        if (book.title == keyword || book.author == keyword || book.ISBN == keyword) {
            cout << "Book Found: " << book.title << " by " << book.author 
                 << " (ISBN: " << book.ISBN << ") - " 
                 << (book.isAvailable ? "Available" : "Checked Out") << endl;
            found = true;
        }
    }

    if (!found) cout << "No book found!\n";
}

// Function to check out a book
void checkoutBook() {
    string borrowerName, ISBN;
    cout << "Enter Borrower's Name: ";
    cin.ignore();
    getline(cin, borrowerName);
    cout << "Enter ISBN of the book to check out: ";
    getline(cin, ISBN);

    for (auto& book : books) {
        if (book.ISBN == ISBN && book.isAvailable) {
            book.isAvailable = false;
            borrowers.push_back(Borrower(borrowerName, ISBN));
            cout << "Book checked out successfully!\n";
            return;
        }
    }

    cout << "Book not available or invalid ISBN!\n";
}

// Function to return a book
void returnBook() {
    string ISBN;
    cout << "Enter ISBN of the book to return: ";
    cin.ignore();
    getline(cin, ISBN);
    
    time_t now;
    time(&now);
    
    for (auto it = borrowers.begin(); it != borrowers.end(); ++it) {
        if (it->borrowedISBN == ISBN) {
            double daysBorrowed = difftime(now, it->borrowDate) / (60 * 60 * 24);
            double fine = (daysBorrowed > 14) ? (daysBorrowed - 14) * 2 : 0;

            for (auto& book : books) {
                if (book.ISBN == ISBN) {
                    book.isAvailable = true;
                    break;
                }
            }

            cout << "Book returned successfully!\n";
            if (fine > 0) {
                cout << "Late return! Fine amount: $" << fine << "\n";
            }
            borrowers.erase(it);
            return;
        }
    }
    
    cout << "Book return failed! Invalid ISBN or book was not checked out.\n";
}

// Function to display all books
void displayBooks() {
    if (books.empty()) {
        cout << "No books available in the library.\n";
        return;
    }
    
    cout << "\nLibrary Books:\n";
    for (const auto& book : books) {
        cout << "Title: " << book.title << " | Author: " << book.author
             << " | ISBN: " << book.ISBN << " | Status: "
             << (book.isAvailable ? "Available" : "Checked Out") << endl;
    }
}

// Function to display menu
void showMenu() {
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Search Book\n";
    cout << "3. Check Out Book\n";
    cout << "4. Return Book\n";
    cout << "5. View All Books\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: checkoutBook(); break;
            case 4: returnBook(); break;
            case 5: displayBooks(); break;
            case 6: cout << "Exiting... Thank you for using the library system!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}
//Output:
/*Library Management System
1. Add Book
2. Search Book
3. Check Out Book
4. Return Book
5. View All Books
6. Exit
Enter your choice: 1
Enter Book Title: BIOLOGY KINGDOM
Enter Author Name: Swarnava
Enter ISBN: 22
Book added successfully!

Library Management System
1. Add Book
2. Search Book
3. Check Out Book
4. Return Book
5. View All Books
6. Exit
Enter your choice: 1
Enter Book Title: AISHWARYA RAI QUEEN
Enter Author Name: Rabisankar
Enter ISBN: 45
Book added successfully!

Library Management System
1. Add Book
2. Search Book
3. Check Out Book
4. Return Book
5. View All Books
6. Exit
Enter your choice: 2
Enter title, author, or ISBN to search: 22
Book Found: BIOLOGY KINGDOM by Swarnava (ISBN: 22) - Available

Library Management System
1. Add Book
2. Search Book
3. Check Out Book
4. Return Book
5. View All Books
6. Exit
Enter your choice: 2
Enter title, author, or ISBN to search: 45
Book Found: AISHWARYA RAI QUEEN by Rabisankar (ISBN: 45) - Available

Library Management System
1. Add Book
2. Search Book
3. Check Out Book
4. Return Book
5. View All Books
6. Exit
Enter your choice: 3
Enter Borrower's Name: Sutrishna
Enter ISBN of the book to check out: 45
Book checked out successfully!

Library Management System
1. Add Book
2. Search Book
3. Check Out Book
4. Return Book
5. View All Books
6. Exit
Enter your choice: 4
Enter ISBN of the book to return: 22
Book return failed! Invalid ISBN or book was not checked out.

Library Management System
1. Add Book
2. Search Book
3. Check Out Book
4. Return Book
5. View All Books
6. Exit
Enter your choice: 4
Enter ISBN of the book to return: 45
Book returned successfully!

Library Management System
1. Add Book
2. Search Book
3. Check Out Book
4. Return Book
5. View All Books
6. Exit
Enter your choice: 5

Library Books:
Title: BIOLOGY KINGDOM | Author: Swarnava | ISBN: 22 | Status: Available
Title: AISHWARYA RAI QUEEN | Author: Rabisankar | ISBN: 45 | Status: Available

Library Management System
1. Add Book
2. Search Book
3. Check Out Book
4. Return Book
5. View All Books
6. Exit
Enter your choice: 6
Exiting... Thank you for using the library system! */
