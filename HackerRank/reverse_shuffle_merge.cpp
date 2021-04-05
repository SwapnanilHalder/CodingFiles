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
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
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
#define int long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{0}; cin >> x
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}



int next_index(int index, int &limit, map<char, vector<int>> &str_map, string &target) {
    for(int i = index; i<target.size(); i++) {
        int failure = 0;
        int new_limit{-1};
        int k = 0;
        while(str_map[target[i]][k] <= limit) k++;
        new_limit = str_map[target[i]][k]; cout << " NEW LIMIT : "  << new_limit<<endl;
        for(int j{index}; j<target.size(); j++) {
            for(int l{0}; l < str_map[target[j]].size() ; l++) {
                if(str_map[target[j]][l] >= new_limit) continue;
                else if(str_map[target[j]].back() < new_limit) {
                    failure = 1;
                    break;
                }
            }
        }
        if(failure == 0) {
            // cout << "Returning " << target[i] << endl;
            limit = new_limit;
            str_map[target[i]].erase(str_map[target[i]].begin() + k);
            return i;
        } 
    }
    return 0;
}

int32_t main() {
    string str; cin >> str;
    int n = str.size();
    map<char, vector<int>> str_map;    
    for(int i{0}; i<n/2 ; i++) {
        swap(str[i], str[n-1-i]);
    }
    for(int i{0}; i < n; i++) {
        str_map[str[i]].push_back(i);
    }
    // cout << str << endl;
    map<char, vector<int>>::iterator it;
    string target;
    for(it = str_map.begin(); it != str_map.end(); it++) {
        for(int i{0}; i<it->second.size()/2; i++)
        target.push_back(it->first);
        cout << it->first << " : " << it->second[0] << " " << it->second[1]<<endl;
    } 
    cout << target << endl;
    char t = target[0];
    int index = str_map[t][0];
    for(int i{1}; i < target.size(); i++) {
        swap(target[i], target[next_index(i, index, str_map, target)]);
        // cout << " New Limit : "  << index << endl;
    }
    cout << target << endl;
}