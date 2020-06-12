#include<bits/stdc++.h>
using namespace std;
class Item{
    int number;
    float cost;
public:
    void getData(int number, float cost){
        this->number=number;
        this->cost=cost;
    }
    void putData(){
        cout<<"Number: "<<number<<endl;
        cout<<"Cost :"<<cost<<endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Item x;
    x.getData(15, 30.0);
    x.putData();

}
