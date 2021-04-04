#include<bits/stdc++.h>
using namespace std;

class Class_2;
class Class_1{
    int value1;
public:
    void setdata(int a){value1 = a;}
    void putdata(){
        cout<<"value1: "<<value1<<endl;;
    }
    friend void exchange1(Class_1 &, Class_2 &);
};
class Class_2{
    int value2;
public:
    void setdata(int b){value2=b;}
    void putdata(){
    cout<<"value2: "<<value2<<endl;
    }
    friend void exchange1(Class_1 &, Class_2 &);
};

void exchange1(Class_1 &x, Class_2 &y){
    int temp=x.value1;
    x.value1=y.value2;
    y.value2=temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Class_1 x;
    Class_2 y;
    x.setdata(100);
    y.setdata(200);
    cout<<"values before Exchange:"<<endl;
    x.putdata();
    y.putdata();

    exchange1(x,y);
    cout<<"values after Exchange:"<<endl;
    x.putdata();
    y.putdata();
}
















