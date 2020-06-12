#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
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

lli tot_avai{0};

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
    For(l, 0, t) {
        vi input = input1l();
        lli count{input[2]};
        lli lastmem{input[2]};
        For(i, 0, input[1]-1) {
            lastmem = lastmem * input[3];
            count += lastmem;
        }
        lli remain = input[0] - count;
        if( remain > 0 ) {
            cout << "POSSIBLE " << remain<< endl;
        } else {
            cout << "IMPOSSIBLE " << -remain<< endl;
        }
        tot_avai += (input[0] - count);
    }
    if(tot_avai>0)
        cout << "POSSIBLE" <<endl;
    else cout << "IMPOSSIBLE" << endl;
}