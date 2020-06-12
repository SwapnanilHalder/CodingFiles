#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

template <class T>
    T myMax(T x, T y){
        return (x>y)?x:y;
    }

int main(){
    SPEED;
    cout<< myMax<int>(3,7)<<endl;
    cout<< myMax<char>('a', 'c')<<endl;
    for (char a = 0; a <= 225; a++)
        cout << a;
    return 0;

}
