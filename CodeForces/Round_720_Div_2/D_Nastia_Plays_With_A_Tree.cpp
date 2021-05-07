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
#define END cout<<"\n"
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{0}; cin >> x
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

int choose_one(int k, int i, vi2d &graph, vi &degree) {
    cout << "Entered : " << k<<endl;
    while(degree[k] != 1) {
        For(j, 1, graph.size()) {
            if(graph[k][i] == 1) {
                i = k;
                k = j;
                break;
            }
        }
    }
    cout << "Returning : " << k <<endl;
    return k;
}

void sol() {
    inpt(n);
    deb(n);
    vi2d graph(n+1, vi(n+1, 0));
    vi degree(n+1, 0);
    vi ones;
    int x, y;
    For(i, 0, n-1) {
        deb(i+1);
        cin >> x;
        pl("HI");
        cin >> y;
        pl("HELLO");
        graph[x][y] = 1;
        graph[y][x] = 1;
        degree[x]++;
        degree[y]++;
        pl("DONE");
    }
    pl("NOWWW");
    pv2d(graph);
    pv(degree);
    loop(it, degree) {
        if (*it == 1) {
            ones.pb(*it);
        }
    }
    int oness = ones.size();
    vi ans(4, 0);
    int first, second, the_one, total = 0;
    For(i, 1, degree.size()) {
        if (degree[i] > 2) {
            For(j, 1, graph.size()) {
                if(graph[i][j] == 1) {
                    For(k, j+1, graph.size()) {
                        if(graph[i][k] == 1) {
                            the_one = choose_one(k, i, graph, degree);
                            break;
                        }
                    }
                    ans = {i, j, j, the_one};
                    degree[the_one] ++;
                    graph[i][j] = 0;
                    graph[j][i] = 0;
                    graph[j][the_one] = 1;
                    graph[the_one][j] = 1;
                    total++;
                    pv(ans);
                }
            }
        }
    }
}

int32_t main() {
    SPEED;
    inpt(t); 
    while(t--) {
        sol();
    }
}

/*

1
17
1 2
1 3
1 5
1 4
2 6
2 8
2 7
6 17
7 16
7 15
3 9
3 10
3 11
9 12
10 14
10 13

*/