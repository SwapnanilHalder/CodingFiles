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

int main() {
    // char p{'a'}, c{'h'};
    // pl(Max<char>(p, c));
    // pl(gcd(15,25));
    // pl(lcm(15,25));
    // vi v{15,48,-895,26};
    // pl(*max_element(all(v)));

    int a, b, c;
    for (b=c=10; a="Hello!Welcome to GeeksForGeeks.\
      TFy!QJu ROo TNn(ROo)SLq SLq ULo+\
      UHs UJq TNn*RPn/QPbEWS_JSWQAIJO^\
      NBELPeHBFHT}TnALVlBLOFAkHFOuFETp\
      HCStHAUFAgcEAelclcn^r^r\\tZvYxXy\
      T|S~Pn SPm SOn TNn ULo0ULo#ULo-W\
      Hq!WFs XDt!" [b+++21]; )
  
      for (; a-- > 64 ; )
         putchar ( ++c=='Z' ? c = c/ 9:33^b&1);
    return 0;
}