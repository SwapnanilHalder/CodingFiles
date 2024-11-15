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

vi calculate(4000001), C_ount(4000001, 0);

void pre_process() {
    // pl("ENTERED");
    For(i, 0, 4000002) {
        // pl("HI");
        calculate[i] = i;
    }
    // pl("1st done");
    For(i ,2, 4000001) {
        // pl("HELLO");
        if(calculate[i] == i) {
            calculate[i] = i-1;
            for(int j= 2*i;j < 4000001; j+= i) {
                calculate[j] = (calculate[j]/i) *(i-1);
            }
        }     
    }
    // pl("2nd done");

    For(i, 1, 4000001) {
        C_ount[i] += (i-1);
        // pl("Entered 3rd");
        for(int j= 2*i;j < 4000001; j+= i) {
            C_ount[j] += i* ((1+calculate[j/i]) / 2);
        }
        // pl("looped");
    }
    // pl("3rd done");
    // pl("DONE");
}

void sol() {
    int k;
    scanf("%d", &k);
    // pl("DONE");
    printf("%d\n", C_ount[4*k+1]);
    return;
}

int32_t main() {
    int t;
    scanf("%d", &t); 
    pre_process();
    while(t--) {
        sol();
    }
}