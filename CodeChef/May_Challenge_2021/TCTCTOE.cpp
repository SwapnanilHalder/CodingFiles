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

void sol() {
    vector<vector<char>> board(3, vector<char> (3, '_'));
    int xs=0, os = 0;
    For(i, 0, 3) {
        For(j, 0, 3) {
            cin >> board[i][j];
            if (board[i][j] == 'X') 
                xs++;
            else if (board[i][j] == 'O')
                os++;
        }
    }
    // deb(xs); deb(os);

    if( ! ( (os == xs) || (os == xs-1) ) ) {
        pl("3"); return;
    }
    int winx=0, wino = 0;
    For(i, 0, 3) {
        if( (board[i][0] != '_') && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) ) {
            if(board[i][0] == 'X') {
                winx++;
            }
            if(board[i][0] == 'O') {
                wino++;
            }            
        }

        if( (board[0][i] != '_') && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) ) {
            if(board[0][i] == 'X') {
                winx++;
            }
            if(board[0][i] == 'O') {
                wino++;
            }            
        }
    
    }
    if( (board[0][0] != '_') && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) ) {
        if(board[0][0] == 'X') {
            winx++;
            // deb(winx);
        }
        if(board[0][0] == 'O') {
            wino++;
            // deb(wino);
        } 
    }

    if( (board[0][2] != '_') && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) ) {
        if(board[0][2] == 'X') {
            winx++;
            // deb(winx);
        }
        if(board[0][2] == 'O') {
            wino++;
            // deb(wino);
        } 
    }
    // deb(winx); deb(wino);

    if( (wino + winx) > 1) {
        if(winx == 2) {
            pl("1"); return;
        }
        else pl("3"); return;
    }
    if( wino == 1 ) {
        if(xs == os) {
            pl("1"); return;
        }
        else {
            pl("3"); return;
        } 
    }
    if(winx == 1) {
        if(xs == (os + 1 )) {
            pl("1"); return;
        }
        else {
            pl("3"); return;
        } 
    }
    if( (wino+winx) == 0 ) {
        if (xs+os == 9) {
            pl("1"); return;
        }
        else if (xs+os < 9) {
            pl("2"); return;
        }
    }

    // pv2d(board);
}

int32_t main() {
    SPEED;
    inpt(t); 
    while(t--) {
        sol();
    }
}