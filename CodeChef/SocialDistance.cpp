#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define ll long long
#define int long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << #x << "=" << x << endl
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, a) for(const auto &it = a.begin(); it != a.end(); it++)
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}

vi input1l(){
    vi input(0);
    string str, num;
    getline(cin, str);
    stringstream X(str);
    while(getline(X, num, ' ')) {
        input.pb(stoi(num));
    }
    //pv(input);
    return input;
}

void solve() {
    vi v=input1l();
    string arr1;
    getline(cin, arr1);
    vi arr;
    for(const auto &i:arr1) {
        arr.pb(i-48);
    }
    int count{0};
    int temp{0};
    int k = v[1];
    int n = v[0];
    if(k >= n){
        if(n>0) {
            count++;
        }
    }
    if(arr[0] != 1) {
        int p = 0;
        int c{0};
        while(arr[p] != 1 && p < arr.size()) {
            c++;
            p++;
        }
        if(c > k) {arr[0] = 1; count++;}
    }
    if(arr[n-1] == 0) {
        int p = n-1;
        int c{0};
        while(arr[p] != 1 && p >= 0) {
            c++;
            p--;
        }
        if(c > k) {arr[n-1] = 1; count++;}
    }
    For(i,0,arr.size()) {
        if(arr[i] == 1 ) {
            count += (temp-k)/(k+1);
            temp = 0;
        } else {
            temp++;
        }
    }
    count += (temp-k)/(k+1);
    temp = 0;

    //pl("Final count");
    pl(count);
    pv(arr);
}

int32_t main() {
    SPEED;
    int t{0};
    cin >> t;
    cinbuffer;
    while(t--) {
        solve();
    }
}