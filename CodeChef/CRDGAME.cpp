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
#define deb(x) cout << #x << " = " << x << endl
#define inpt(x) int x{0}; cin >> x
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, a) for(const auto &it = a.begin(); it != a.end(); it++)
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
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

int sumdigit(int m) {
    int sum{0};
    while(m > 0) {
        sum += m % 10;
        m /= 10;
    }
    return sum;
}

void sol() {
    inpt(n);
    cinbuffer;
    vi res(2, 0);
    For(i, 0, n) {
        vi v = input1l();
        int sum1 = sumdigit(v[0]) ; int sum2 = sumdigit(v[1]) ;
        if( sum1 > sum2 ) res[0]++;
        else if ( sum1 < sum2 ) res[1]++;
        else { res[0]++ ; res[1]++ ; }
    }
    if(res[0] > res[1]) { cout << "0 " << res[0] << endl ;}
    if(res[0] < res[1]) { cout << "1 " << res[1] << endl ;} 
    if(res[0] == res[1]) { cout << "2 " << res[0] << endl ;} 
}

int32_t main() {
    inpt(t);
    while(t--) {
        sol();
    }
}