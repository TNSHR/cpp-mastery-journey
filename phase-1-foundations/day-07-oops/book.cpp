#include<iostream>
using namespace std;

class Book{
    public:
        string title;
        string author;
        int pages;

        void display(){
            cout << "Title:" << title << endl;
            cout << "Author:" << author << endl;
            cout << "Pages:" << pages << endl;
        }
};


int main(){
    Book b1, b2, b3, b4, b5;
    b1.title = "The Great Gatsby";
    b1.author = "F. Scott Fitzgerald";
    b1.pages = 180;

    b2.title = "To Kill a Mockingbird";
    b2.author = "Harper Lee";
    b2.pages = 281;

    b3.title = "1984";
    b3.author = "George Orwell";
    b3.pages = 328;

    b4.title = "Pride and Prejudice";
    b4.author = "Jane Austen";
    b4.pages = 432;

    b5.title = "The Catcher in the Rye";
    b5.author = "J.D. Salinger";
    b5.pages = 277;

    b1.display();
    b2.display();
    b3.display();
    b4.display();
    b5.display();
    return 0;
}