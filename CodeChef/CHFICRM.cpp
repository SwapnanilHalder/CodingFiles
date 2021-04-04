#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<lli>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define ll long long
#define lli long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define deb(x) cout << #x << "=" << x << endl
#define pl(x) cout << x << endl
using namespace std;

vi input1l(){
    vi input(0);
    string str, num;
    getline(cin, str);
    stringstream X(str);
    while(getline(X, num, ' ')) {
        if((stoi(num) % 5 == 0) && (stoi(num) <= 15)) {
            input.pb(stoi(num) / 5); // divided by 5 to decrease the range to 1s (problem specific)
        } else return vi{-1};
    }
    //printvec(input);
    return input;
}

int main() {
    SPEED;
    int t{0};
    cin >> t;
    cinbuffer;
    For(l, 0, t){
        int succeed{1};
        int n{0};
        cin >> n;
        cinbuffer;
        vi input = input1l();
        vi coin(4);
        coin[0] = n;
        //pv(input);
        //pv(coin);
        if(input[0] != -1) {
            int chef{0};
            For(i, 0, input.size()) {
                if(chef >= (input[i] - 1)) {
                    // deb(chef);
                    // deb(input[i]);
                    if(input[i] == 3) {
                        if( (coin[(input[i] - 1)] >= 1 ) || (coin[(input[i] - 2)] >= 2 ) ){
                            chef++;
                            if (coin[(input[i] - 1)] >= 1) {
                                coin[(input[i] - 1)] -= 1;
                            } else {
                                coin[(input[i] - 2)] -= 2;
                            }
                            coin[input[i]]++;
                            //pv(coin);
                        } else succeed = 0;
                    }
                    else {
                        if( (coin[(input[i] - 1)] >= 1 ) ){
                            chef++;
                            if (coin[(input[i] - 1)] >= 1) {
                                coin[(input[i] - 1)] -= 1;
                            }
                            coin[input[i]]++;
                            //pv(coin);
                        } else succeed = 0;    
                    }
                } else {
                    // deb(chef);
                    // deb(input[i]); 
                    //pv(coin);              
                    succeed = 0;
                }
            }
            if(succeed == 1) pl("YES");
            else pl("NO");
        }
        else pl("NO");
    }
}