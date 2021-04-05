#include<bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str="hell";
    string & rstr= str;                                   //&(variable) makes the variable an lvalue variable, which can hold lalue, i.e. named permanent variable
    cout<<rstr<<endl<<str<<endl;
    cout<<rstr[0]<<endl<<&str[0]<<endl;
    rstr +='o';
    bool cond = (&str==&rstr);
    cout<<"Cond ="<<cond<<endl;
    string &&bad1="hello";                                //&&(variable) made the variable an rvalue variable, which can hold rvalue,i.e. temporary value
    string &&bad2=str + "";
    string &&sub = str.substr(0,4);
    cout<<"&&bad1:\t"<<bad1<<"\n&&bad2:\t"<<bad2<<"\n&&sub:\t"<<sub<<endl;


}
