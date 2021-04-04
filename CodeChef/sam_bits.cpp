#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<unordered_map>
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
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{0}; cin >> x
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " :  " << itr->second;END;}
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
    
    return input;
}

int find_largest(int n) {
    bitset <20> bits(n);
    int i{0};
    for(i; i<20; i++) {
        if(bits[19-i] != 0) break;
    }
    vector<bool> v;
    for(i; i<20; i++) {
        v.pb(bits[19-i]);
    }
    
    return v.size();
}
vi decToBinary(int n) 
{ 
    vi v;
    int binaryNum[32];     
    int i = 0; 
    while (n > 0) {        
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    }       
    for (int j = i - 1; j >= 0; j--) 
        v.pb( binaryNum[j] ); 
    return v;
} 

void sol() {
    vi v = {2,7,10};
    const int sized = find_largest(*max_element(all(v)));
    vi2d v2;
    For(i, 0, v.size()) {
        v2.pb(decToBinary(v[i]));
    }
    //pv2d(v2);
    vi2d v01(v.size(), vi(2, 0));
    For(i, 0, v2.size()) {
        For(j, 0, v2[i].size()) {
            if(v2[i][j] == 1) v01[i][1]++;
        }
        v01[i][0] = sized - v01[i][1];
    }
    // pv2d(v01);

    int count{0};
    vi vfinal(sized+1, 0);
    For(i, 0, v01.size()) {
        vfinal[v01[i][0]]++;
    }
    //pv(vfinal);
    int success = 1;
    int singlecouple{0};
    For(i, 0, (vfinal.size()+1)/2) { 
        singlecouple += vfinal[i];
        if(vfinal[i] != vfinal[vfinal.size() - i-1]) {
            success = 0;
            break;
        }
    }
    if(success == 0) {
        bitset<20> ans(0);
        for(int i = sized-1; i>=0; i--){
            cout<<ans[i];
        }
    }
    else {
        int totalcouple = (singlecouple)* (singlecouple + 1) / 2;
        bitset<20>ans1(totalcouple);
        for(int i = sized-1; i>=0; i--){
            cout<<ans1[i];
        }END;
    }
}
int32_t main() {
    sol();
}