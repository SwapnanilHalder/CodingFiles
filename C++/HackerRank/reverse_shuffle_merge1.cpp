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


void p_map(map<char, vector<int>> &str_map) {
    loop(itr, str_map) {
        cout << "\t" << itr->first << " ->  ";
        pv(itr->second);
    }
}

void optimise(int &index, int &restriction, int &filled, string &target, map<char, vector<int>> &str_map, map<char, int> &total_left) ;
bool suff_after_index(int &index, char &ch, map<char, vector<int>> &str_map, map<char, int> total_left);
int32_t main() {
    // system("clear");
    string str; cin >> str;
    int n = str.size();
    map<char, vector<int>> str_map;  
    map<char, int> total_left;  
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
        for(int i{0}; i<it->second.size()/2; i++) {
            target.push_back(it->first);
            total_left[it->first]++;
        }
    } 
    p_map(str_map);
    cout << target << endl;
    int index = str_map[target[0]][0];
    int restriction = 0;
    int filled = 0;
    pmint(total_left);
    For(i, 0, target.size()) {
        deb(index); deb(restriction); deb(filled) ; deb(target[filled]);
        optimise(index, restriction, filled, target, str_map, total_left);
    }
}

void optimise(int &index, int &restriction, int &filled, string &target, map<char, vector<int>> &str_map, map<char, int> &total_left) {
    char ch = target[filled];
    bool possible = suff_after_index(index, target[filled], str_map, total_left);
    int i = filled;
    while( possible != 1 ) {
        i = filled; 
        for(i = filled; i< target.size() && target[i] == ch; i++) {
            cout << target[i] << " ";
            deb(filled);   
            deb(target);
        }
        ch = target[i]; cout << "selected char : " << ch  << " this"<< endl;
        vector<int>::iterator it = str_map[target[i]].begin();
        while(*it <= restriction ) it++;
        index = *it;
        cout << ch << "   index is : " << index << endl;
        possible = suff_after_index(index, target[i], str_map, total_left);
    }
    swap(target[i], target[filled]);
    cout << "After change : " << target << endl;
    total_left[ch]--;
    filled++;
    restriction = index;
    vector<int>::iterator position = find(all(str_map[ch]), index);
    if(position != str_map[ch].end()) str_map[ch].erase(position); p_map(str_map);
    loop(itr, str_map[target[filled+1]]) {
        if(*itr > restriction) {
            index = *itr;break;
        }
    }
    cout << filled << "th position done\n";
}

bool suff_after_index(int &index, char &ch, map<char, vector<int>> &str_map, map<char, int> total_left) {
    total_left[ch] -= 1;
    loop(itr, total_left) {
        int req = itr->second;
        loop(it, str_map[ch]) {
            if(*it > index) total_left[ch]--;
        }
        if(total_left[ch] > 0 ) {
            cout << ch << " is not enough after " << index<<endl;
            return 0;
        }
    } 
    cout << ch << " is the selected" << endl;
    return 1;
}




// sbcnzxqnrygkocahxjebvueaawwcythjdrhvizqsshgtwdolmillxpshxpxqrywkivceufclhydhshrklkphajbftuapiocjlcthfirhgaohfysqjolssbzhbovdstbyqdpnjbpfmgqrzfctcwcrztvgbegunarvecseoulabaonguckqbtrvuagreyclyjytpvozqdnhldlnsocenuzksawirgsbjobpldjdlrxbricrauuksbmecvvwagnnacaqghmjpzrlsvlpbbcuaddgvlhvuvkxexjcfhxrodmcwlrzyyiksuksshhonahsyzbbprwuitmoyoqurtqsaslevgvpfbzkkhgcnpjdpseuiylluvdetsqssbrxpiclxxvosuqipsqvvwsezhl