#include <iostream>
#include <string>
using namespace std;

class Publication {
    public:
        string title;
        float price;
        void getdata() {
            cout << "Enter the title : ";
            cin >> title;
            cout << "Price : ";
            cin >> price;
        }
        void putdata() {
            cout << "Title : " << title<< endl;
            cout << "Price : " << price << endl;
        }
};

class Book : public Publication {
    private:
        int page_count;
    public:
        void getdata() {
            cout << "Number of pages in book : ";
            cin >> page_count;
        }
        void putdata() {
            cout << "Number of pages => " << page_count<<endl;
        }
};

class Tape : public Publication {
    private:
        float play_time;
    public:
        void getdata() {
            cout << "Playing time in minutes : ";
            cin >> play_time;
        }
        void putdata() {
            cout << "Total play time : " << play_time<<endl;
        }
};

int main () {
    Book book1;
    book1.getdata();
    book1.putdata();
}