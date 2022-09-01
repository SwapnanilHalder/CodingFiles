#include <iostream>
#include <sstream>
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
#define pv(v) for(const auto &i: v){cout<<i<<" ";}cout << "\n"
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;for(auto itr = v.begin(); itr != v.end(); itr++){cout << "\t" << itr->first << " ->  " << itr->second;cout << "\n";}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";cout << "\n"
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}

class Solution {
public:
    int answer=0;
    int count=0;
    int obstacles=0;
    int target=0;
    int m, n;
    bool isValid(int x, int y) {
        if(x < 0 || x >= m || y<0 || y>=n)
            return 0;
        return 1;
    }
    void DFS(int x, int y, vector<vector<int>>& grid) {
        cout << x << " , " << y << endl;
        if(!isValid(x, y) )
            return;
        if(grid[x][y] == -1 || grid[x][y] == 5)
            return;
        if(grid[x][y] == 2) {
            if(count == target) {
                answer++;
                deb(answer);
            }
            return;
        }
        grid[x][y] = 5; count++;
        DFS(x+1, y, grid); DFS(x, y+1, grid); DFS(x-1, y, grid); DFS(x, y-1, grid);
        grid[x][y] = 0; count--;

    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n =grid[0].size();
        int st_x, st_y, end_x, end_y;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    st_x = i, st_y = j;
                }
                if(grid[i][j] == 2) {
                    end_x = i, end_y = j;
                }
                if(grid[i][j] == -1) {
                    obstacles++;
                }
            }
        }
        target = m*n-1-obstacles;
        DFS(st_x, st_y, grid);
        return answer;
    }
};


int main() {
    Solution mySolution;
    vector<vector<int>> arr{{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    // int start = 5;
    // string str = "abcdefg";
    cout << "Answer : " << endl;
    cout << mySolution.uniquePathsIII(arr) << endl;
}