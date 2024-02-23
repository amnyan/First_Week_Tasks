#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;

public:

    Book(const string& t, const string& a, const string& i) : title(t), author(a), isbn(i) {}


    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getISBN() const {
        return isbn;
    }


    void setTitle(const string& t) {
        title = t;
    }

    void setAuthor(const string& a) {
        author = a;
    }

    void setISBN(const string& i) {
        isbn = i;
    }
};

int main() {
    Book book("The C++ Programming Language", "Bjarne Stroustrup", "978-3-0");

    cout << "Title: " << book.getTitle() << endl;
    cout << "Author: " << book.getAuthor() << endl;
    cout << "ISBN: " << book.getISBN() << endl;


    book.setTitle("Tour of C++");
    book.setAuthor("Bjarne Stroustrup");
    book.setISBN("978-000");

    cout << "\nUpdated Title: " << book.getTitle() << endl;
    cout << "Updated Author: " << book.getAuthor() << endl;
    cout << "Updated ISBN: " << book.getISBN() << endl;

    return 0;
}
