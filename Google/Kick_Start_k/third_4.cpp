#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <numeric>
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define li list<int>
#define mii map<int, int>
#define msi map<string, int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
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
#define pmpair(v) cout << "	(" << v.first << " , " << v.second << ")";END
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}

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

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return (a.first < b.first);
}

bool check(int x, vector<pair<int, int>>::iterator &p, vi &sol, vector<pair<int, int>> &store) {
    if(x < p->first || x > p->second) {
        return 0;
    }
    int succ = 0;
    if(x == p->first) {
        succ = 1;
        sol.pb(x);
        if(p->first == p->second) {
            store.erase(p);
        }
        else {
            p->first++;
        }
    }
    else if(x == p->second) {
        succ = 1;
        sol.pb(x);
        p->second--;
    }
    else if(x > p->first && x < p->second) {
        succ = 1;
        sol.pb(x);
        int temp = p->second;
        p->second = x-1;
        p++;
        store.insert(p, pair<int, int> {x+1, temp});
    }
    return (succ == 1);
}

void sol(int t) {
    inpt(n); inpt(m);
    int x, y;
    vector<pair<int, int>> store; 
    For(i, 0, n) {
        cin >> x >> y;
        store.pb({x, y});
    }
    sort(all(store), cmp);
    // For(i, 0, store.size()) {
    //     pmpair(store[i]);
    // }

    cinbuffer;
    vi skill = input1l();
    // pmint(mapp);
    vi sol;
    vector<pair<int, int>>::iterator it;
    bool checked = false;
    For(i, 0, m) {
        it = lower_bound(all(store), pair<int, int> {skill[i], 0});
        if(it == store.begin()) {
            checked = check(skill[i], it, sol, store);
            if(checked == false) {
                if( skill[i] > it->second ) {
                    sol.pb(it->second);
                    it->second--;
                    if(it->first > it->second) {
                        store.erase(it);
                    }
                }
                else {
                    sol.pb(it->first);
                    it->first++;
                    if(it->first > it->second) {
                        store.erase(it);
                    }
                }                
            }
        }
        else {
            it--;
            checked = check(skill[i], it, sol, store);
            if(checked == false) {
                it++;
                checked = check(skill[i], it, sol, store);
            }
            if(checked == false) {
                auto pre = it;
                pre--;
                if(abs(pre->second - skill[i]) <= abs(it->first - skill[i])) {
                    sol.pb(pre->second);
                    pre->second--;
                    if(pre->first > pre->second) {
                        store.erase(pre);
                    }
                }
                else {
                    sol.pb(it->first);
                    it->first++;
                    if(it->first > it->second) {
                        store.erase(it);
                    }
                }
            }
        }
        // For(i, 0, store.size()) {
        //     pmpair(store[i]);
        // }END;END;
    }



    // cout << "Upper bound : {" <<  it->first << " , " << it->second << " }" << endl;
    // it--;
    // cout << "Upper bound : {" <<  it->first << " , " << it->second << " }" << endl;


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