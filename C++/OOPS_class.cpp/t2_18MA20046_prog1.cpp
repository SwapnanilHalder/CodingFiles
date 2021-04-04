#include<iostream>
using namespace std;

class Publication
{
    public: 
        string name;
        float price;
};

class Book:public Publication
{
    public:
    int page_count;

     void get_data()
    {

        cout<<"enter name"<<endl;
        cin>>name;
        cout<<"enter price"<<endl;
        cin>>price;
        cout<<"enter page_count"<<endl;
        cin>>page_count;
    }

    void show_data()
    {
         cout<<"name: "<<name<<endl;
         cout<<"price: "<<price<<endl;
         cout<<"page_count: "<<page_count<<endl;
    }
};

class Tape:public Publication
{
    public:
    int playing_time;

    void get_data()
    {

        cout<<"enter name"<<endl;
        cin>>name;
        cout<<"enter price"<<endl;
        cin>>price;
        cout<<"enter playing_time"<<endl;
        cin>>playing_time;
    }

    void show_data()
    {
         cout<<"name: "<<name<<endl;
         cout<<"price: "<<price<<endl;
         cout<<"playing_time: "<<playing_time<<endl;
    }

};

int main()
{
    Tape tape1;
    Book book1;
    tape1.get_data();
    tape1.show_data();
    book1.get_data();
    book1.show_data();
}