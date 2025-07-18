#include <iostream>
#include <vector>
#include <string>
#include <windows.h>


using namespace std;

struct Book {
    string authorSurname;
    string title;
    int year;
};

void printBook(const Book& book) {
    cout << "Автор: " << book.authorSurname << ", Название: \"" << book.title
         << "\", Год издания: " << book.year << endl;
}

void printAllBooks(const vector<Book>& library) {
    if (library.empty()) {
        cout << "Библиотека пуста." << endl;
        return;
    }
    for (const auto& book : library) {
        printBook(book);
    }
}

void addBook(vector<Book>& library) {
    Book newBook;
    cout << "Введите фамилию автора: ";
    cin >> newBook.authorSurname;
    cin.ignore(); // очистка буфера
    cout << "Введите название книги: ";
    getline(cin, newBook.title);
    cout << "Введите год издания: ";
    cin >> newBook.year;

    library.push_back(newBook);
}

void searchByAuthor(const vector<Book>& library, const string& surname) {
    bool found = false;
    for (const auto& book : library) {
        if (book.authorSurname == surname) {
            printBook(book);
            found = true;
        }
    }
    if (!found) {
        cout << "Книги автора " << surname << " не найдены." << endl;
    }
}

void searchByYear(const vector<Book>& library, int year) {
    bool found = false;
    for (const auto& book : library) {
        if (book.year == year) {
            printBook(book);
            found = true;
        }
    }
    if (!found) {
        cout << "Книги за " << year << " год не найдены." << endl;
    }
}

void searchByAuthorAndYear(const vector<Book>& library, const string& surname, int year) {
    bool found = false;
    for (const auto& book : library) {
        if (book.authorSurname == surname && book.year == year) {
            printBook(book);
            found = true;
        }
    }
    if (!found) {
        cout << "Книги автора " << surname << " за " << year << " год не найдены." << endl;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    vector<Book> library;

    // Добавим несколько книг вручную
    library.push_back({"Толстой", "Война и мир", 1869});
    library.push_back({"Достоевский", "Преступление и наказание", 1866});
    library.push_back({"Булгаков", "Мастер и Маргарита", 1967});

    cout << "\n--- Все книги ---" << endl;
    printAllBooks(library);

    cout << "\n--- Добавление книги вручную ---" << endl;
    addBook(library);

    cout << "\n--- Все книги после добавления ---" << endl;
    printAllBooks(library);

    cout << "\n--- Поиск по автору: 'Толстой' ---" << endl;
    searchByAuthor(library, "Толстой");

    cout << "\n--- Поиск по году: 1967 ---" << endl;
    searchByYear(library, 1967);

    cout << "\n--- Поиск по автору и году: 'Достоевский', 1866 ---" << endl;
    searchByAuthorAndYear(library, "Достоевский", 1866);

    return 0;
}
