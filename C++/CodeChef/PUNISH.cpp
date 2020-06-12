#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<lli>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926536
#define MOD 1000000007
#define ll long long
#define lli long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define printvec(v) for(const auto &i: v){cout<<i<<" ";}END
using namespace std;

vi input1l(){
    vi input(0);
    string str, num;
    getline(cin, str);
    stringstream X(str);
    while(getline(X, num, ' ')) {
        input.pb(stoi(num));
    }
    //printvec(input);
    return input;
}

int main() {
    int t{0};
    cin >> t;
    cinbuffer;
    For(l, 0, t){
        vi input = input1l();
        if((input[1]-1) / (input[0]-1) %2 == 0){
            cout << ((input[1]-1) % (input[0]-1)) + 1 <<endl; 
        }
        if((input[1]-1) / (input[0]-1) %2 != 0){
            cout << input[0] - ((input[1]-1) % (input[0]-1)) <<endl;
        }
    }
}