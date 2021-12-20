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

void sol() {
    cinbuffer;
    inpt(m); inpt(n);
    cinbuffer;
    vi2d arr;
    For(i, 0, m) {
        arr.pb(input1l());
    }
    // pv2d(arr);
    vi best(n, 0), ndbest(n, -1), best_row(n, 0), ndbest_row(n, 0);
    for (int i = 0; i < n; i++) {
        For(j, 0, m) {
            if(arr[j][i] > best[i]  /*arr[best_row[i]][i]*/) {
                best[i] = arr[j][i];
                best_row[i] = j;
            }
        }
    }
    // pv(best_row);
    if(n-1 >= m) {
        pl(*min_element(all(best)));
        return;
    }
    set<int> sett(all(best_row));
    if(sett.size() != best_row.size()) {
        pl(*min_element(all(best)));
        return;  
    }

    for (int i = 0; i < n; i++) {
        For(j, 0, m) {
            if (arr[j][i] != best[i]) {
                // first change the value of second largest
                // as soon as the next element is found
                if (ndbest[i] == -1) {
                    ndbest_row[i] = j;
                    ndbest[i] = arr[j][i];
                }
                else if (arr[j][i] > arr[ndbest_row[i]][i]) {
                    ndbest_row[i] = j;
                    ndbest[i] = arr[j][i];
                }
            }
        }
    }
    int sum = accumulate(all(best), 0);
    int maxm = sum, t_max = 0, tndbest=0, posn=0, posm=0, c_col = 0, ind = 0, mini = 0;
    For(i, 0, n) {
        t_max = 0;
        For(j, 0, n) {
            if(j == i) {
                continue;
            }
            if(t_max < arr[best_row[j]][i]) {
                t_max = arr[best_row[j]][i];
                posm = j;
            }
        }
        // deb(best_row[posm]);
        if (tndbest< sum-best[i]+t_max) {
            tndbest = sum-best[i]+t_max;
            posn = i;
            c_col = posm;
            ind = 1;
        }
        t_max = 0;
        For(j, 0, n) {
            if(j == i) {
                continue;
            }
            if(t_max < arr[ndbest_row[j]][i] + ndbest[j] ) {
                t_max = arr[ndbest_row[j]][i] + ndbest[j];
                posm = j;
            }
        }
        if (tndbest< sum-best[i]-best[posm] +t_max) {
            tndbest = sum-best[i]-best[posm]+t_max;
            posn = i;
            c_col = posm;
            ind = 2;
        }
    }


    // pv(best); pv(ndbest); pv(best_row); pv(ndbest_row);
    // pl(*max_element(all(ndbest)));
    // pl(sum - best[posn] + arr[best_row[c_col]][posn]);
    if(ind == 1) {
        best[posn] -= (sum - tndbest);
    }

    if(ind == 2) {
        mini = min(ndbest[posm], arr[ndbest_row[posm]][posn]);
        best[posm] = ndbest[posm];
        best[posn] = arr[ndbest_row[posm]][posn];
    }
    pl(*min_element(all(best)));
    return;
}

/*

1
4 3
1 3 1
3 1 1
1 2 2
1 1 3

*/

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}