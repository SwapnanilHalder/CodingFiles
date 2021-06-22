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

#define int long long int
#define END cout << "\n" 
#define ENDstd printf("\n")
#define cinbreak cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define input_x(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define print_line(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define vector_int vector<int>
#define vi2d vector<vector<int>> 
#define li list<int>
#define mii map<int, int>
#define msi map<string, int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626

using namespace std;


vector_int input_one_line();

void sol(vector_int &vectorsss, int p) {
    input_x(x);
    int repl = lb( all(vectorsss), x) - vectorsss.begin();
    if( (x == vectorsss[repl]) && (p >repl)  ) {
        print_line("0");
    }
    else {
        if(( (p-repl) % 2) == 1) {
            print_line("NEGATIVE");
        }
        else {
            print_line("POSITIVE");
        }
    }
}


int32_t main() {
    SPEED1;
    input_x(n); input_x(t); cinbreak;
    vector_int vectorsss = input_one_line();
    sort(all(vectorsss));
    int p;
    while(t--) {
        sol(vectorsss, n);
    }
}

vector_int input_one_line()
{
    vector_int input(0);
    string str, num;
    getline(cin, str);
    stringstream X(str);
    while(getline(X, num, ' ')) {
        input.pb(stoll(num));
    }
    //pv(input);
    return input;
}