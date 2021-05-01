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
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}


class Solution {
public:
    static inline bool compare (vector<int> i1, vector<int> i2) {
        return (i1[0] < i2[0]);
    } 
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        sort(rooms.begin(), rooms.end(), compare);
        // pv2d(rooms);
        vector<int> arr{};
        int n = queries.size();
        int roomno = rooms.size();
        int centre = 0;
        int tail = 0;
        // pl("Started :");
        for(int i{0} ;i<n; i++) {
            // pl("ENTERED :");
            centre = roomno-1;
            for(int j{0}; j<roomno ; j++) {
                if(rooms[j][0] >= queries[i][0]) {
                    centre = j;
                    break;
                }
            }
            if(centre != 0) {
                if(abs (rooms[centre][0] - queries[i][0]) > abs(rooms[centre-1][0] - queries[i][0]) ) {
                    centre--;
                }
            }
            // deb(centre);
            if(rooms[centre][1] >= queries[i][1]) {
                // pl("GOT BEFORE WHILE");
                arr.push_back(rooms[centre][0]);
                // pv(arr);
                continue;
            }
            int jump = 1;
            int pushed = 0;
            int succeed = 0;
            arr.push_back(-1);
            while(1) {
                pushed = 0;
                succeed = 0;
                if (( centre - jump) >= 0) {
                    if(rooms[centre-jump][1] >= queries[i][1]) {
                        // pl("GOT IN BEFORE");
                        arr[arr.size()-1] = rooms[centre-jump][0];
                        succeed = 1;
                        pushed = 1;
                    } 
                }
                if (centre+jump <= roomno-1) {
                    if (pushed == 0) {
                        if(rooms[centre+jump][1] >= queries[i][1]) {
                            // pl("GOT IN BEFORE");
                            arr[arr.size()-1] = rooms[centre+jump][0];
                            succeed = 1;
                        }  
                    }
                    else if(pushed == 1) {
                        if (abs (rooms[centre-jump][0] - queries[i][0]) > abs(rooms[centre+jump][0] - queries[i][0]) ) {
                            if(rooms[centre+jump][1] >= queries[i][1]) {
                                // pl("GOT IN AFTER");
                                arr[arr.size()-1] =rooms[centre+jump][0];
                                succeed = 1;
                            } 
                        }
                    }
                    
                }
                jump++;
                // pv(arr);
                // deb(jump);
                if (succeed == 1) {
                    break;
                }
                if ( ((centre - jump) < 0) || ((centre + jump) > roomno-1 ) ) {
                    break;
                }

            }
        }
        return arr;
    }
};


int32_t main() {
    Solution mySolution;
    vector<int> arr{4,2,3,0,3,1,2};
    vector<vector<int>> rooms {{1,4},{2,3},{3,5},{4,1},{5,2}};
    vector<vector<int>> queries { {2,3},{2,4},{2,5} };
    string s = "a1b2c3d4e";
    int start = 5;
    pv( mySolution.closestRoom(rooms, queries) );
}

/*
{{1,4},{2,3},{3,5},{4,1},{5,2}}

{ {2,3},{2,4},{2,5} }

{{2,2}, {1,2}, {3,2}}

{{3,1},{3,3}, {5,2}}

*/