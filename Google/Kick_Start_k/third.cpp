#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <numeric>
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
#define int long long int
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define END cout << "\n" 
#define ENDstd printf("\n")
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END
using namespace std;

vi input1l(){
    vi input(0);
    string str, num;
    getline(cin, str);
    stringstream X(str);
    while(getline(X, num, ' ')) {
        input.pb(stoll(num));
    }
    //pv(input);
    return input;
}

void sol(int t) {
    inpt(n); inpt(m);
    set <int> sett;
    int x, y;
    For(i, 0, n) {
        cin >> x >> y;
        For(j, x, y+1) {
            sett.insert(j);
        }
    }
    cinbuffer;
    vi skill = input1l();
    // pmint(mapp);
    vi sol;
    For(i, 0, m) {
            auto up = sett.lower_bound(skill[i]);
            if(skill[i] == *up) {
                sol.pb(skill[i]);
                sett.erase(skill[i]);   
                continue;             
            }
            int high = *up;
            if(up == sett.begin()) {
                sol.pb(high);
                sett.erase(high);
                continue;
            }
            up--;
            int low = *up;
            if(abs(low-skill[i]) <= abs(high-skill[i])) {
                sol.pb(low);
                sett.erase(low);
            }
            else {
                sol.pb(high);
                sett.erase(high); 
            }
    }
    // pmint(mapp);
    sett.clear();
    cout << "Case #" << t << ": ";
    pv(sol); 
}

int32_t main() {
    SPEED1;
    inpt(t); 
    For(i, 0 ,t) {
        sol(i+1);
    }
}

/*


            prev = i-1, next = i+1;
            while(prev >=0 || next < m) {
                if(prev >= 0) {
                    if(mapp[skill[prev]] == 1) {
                        sol.pb(skill[prev]);
                        mapp.erase(skill[prev]);
                        break;
                    }
                    prev--;
                }
                if(next < m) {
                    if(mapp[skill[next]] == 1) {
                        sol.pb(skill[next]);
                        mapp.erase(skill[next]);
                        break;
                    }
                    next++;
                }
            }


*/