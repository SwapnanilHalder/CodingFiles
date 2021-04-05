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
    SPEED;
    int rooms{0},tv, notv, target;
    cin >> rooms;
    cin >> tv >> notv;
    cin >> target;
    vi monthday{31,28, 31,30,31,30,31,31,30,31,30,31};
    vi patients;
    For(month, 1, 13) {
        For(day, 1, monthday[month-1]+1) {
            int people = pow((6-month),2) + abs(day-15);
            patients.pb(people);
        }
    }
    //pv(patients);

    int notvp = rooms;
    int tvp = 0;
    int tvspent, notvspent, revenue;
    while((revenue < target) && (notvp >=0) && (tvp >=0)) {
        revenue = 0;
        For(i, 0, patients.size()) {
            if(patients[i] < rooms) {
                if (notvp >= patients[i]) {
                    notvspent = patients[i] * notv;
                    tvspent = 0;
                }
                else {
                    notvspent = notvp * notv;
                    tvspent = (patients[i] - notvp) * tv;
                }
                revenue += (notvspent + tvspent);
            }
            else if (patients[i] >= rooms) {
                notvspent = notvp * notv;
                tvspent = tvp * tv ;
                revenue += (notvspent + tvspent) ;
            }
        }
        notvp -= 1;
        tvp += 1;
    }
    pl(tvp-1);
}