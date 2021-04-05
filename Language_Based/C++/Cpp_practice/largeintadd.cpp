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
#define lli long long int
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

string findsum(string num1, string num2) {
    //pl(num1);pl(num2);
    reverse(all(num1));reverse(all(num2));
    if(num1.length() > num2.length())
        swap(num1, num2); //num2 is greater
    while(num1.length() != num2.length()) num1.pb('0');
    string res = "";
    int carry{0}, sit{0}, temp{0}; 
    int n1 = num1.length(), i{0}, j{0};
    while(i < n1) {
        int num11 = (num1[i]-'0'), num22 = (num2[i]-'0');
        int temp = num11 + num22 + carry;
        sit = temp %10; carry = temp / 10;
        res.pb(sit+'0');
        i++;
    }
    //deb(carry);
    if(carry != 0) res.pb(carry+'0');
    reverse(all(res));
    return res;
}

int main() {
    string num1, num2;
    // cin >> num1;
    // cin >> num2;
    num1 = "990000000000000", num2 = "000009";
    string res = findsum(num1, num2);
    cout << res<<endl;
}