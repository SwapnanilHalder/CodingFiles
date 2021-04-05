#include<bits/stdc++.h>
using namespace std;

void swap(vector <string> &x, vector<string> &y){
    vector<string> temp = x;
    x = y;
    y = temp;

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> x{5, 10, 15, 20}, y{10, 20, 50, 100};
    cout<< x.at(0)<<endl<<y.at(0)<<endl;

    swap(x,y);
    cout<< x.at(0)<<endl<<y.at(0)<<endl;
    cout<<"Type of x                     "<<typeid(x).name()<<"\ntype of &x                     "<<typeid(&x).name()<<endl<<"Type of 5                      "<<typeid(5).name()<<endl;
}
