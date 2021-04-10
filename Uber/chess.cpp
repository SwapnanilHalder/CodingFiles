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
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END
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
    //pv(input);
    return input;
}

bool check_surr (int i, int j, vi2d &dp) {
    // cout << "Entered : " << i << " ," << j << endl;
    int failed = 0;
    For(k, -1, 2) {
        For(l, -1, 2) {
            if(k != 0 || l!= 0) {
                if(dp[i+k][j+l] == 0) {
                    // cout <<"nooo : "<< i+k << " & " << j+l << endl;
                    failed = 1;
                    return true;
                }
            }
        }
    }
    return false;
}

vector<int> ninjaChess2021(string king, string ninja) {
    int k_a{0}, k_b{0} ,n_a{0}, n_b{0};
    k_a = king[0] - 'a' + 1;
    k_b = king[1] - '0';
    n_a = ninja[0] - 'a' + 1;
    n_b = ninja[1] - '0';
    // deb(k_a);deb(k_b);deb(n_a);deb(n_b);
    
    vi2d dp(10, vi(10,0));
    For(i, 0, 10) {
        For(j, 0, 10) {
            if(i== 0 || j== 0 || i == 9|| j == 9) {
                dp[i][j] = 1;
            }
        }
    }
    For(i, k_a -1, k_a+2) {
        For(j, k_b-1, k_b+2) {
            dp[i][j] = 1;
        }
    }
    // pv2d(dp);END;
    
    if( ( n_a+1 ) >=0 && ( n_a+1 ) <= 9 && ( n_b+2 )>= 0 && ( n_b+2 ) <= 9)     dp[n_a+1][n_b+2] = 1;
    if( ( n_a+1 ) >=0 && ( n_a+1 ) <= 9 && ( n_b-2 )>= 0 && ( n_b-2 ) <= 9)     dp[n_a+1][n_b-2] = 1;
    if( ( n_a-1 ) >=0 && ( n_a-1 ) <= 9 && ( n_b+2 )>= 0 && ( n_b+2 ) <= 9)     dp[n_a-1][n_b+2] = 1;
    if( ( n_a-1 ) >=0 && ( n_a-1 ) <= 9 && ( n_b-2 )>= 0 && ( n_b-2 ) <= 9)     dp[n_a-1][n_b-2] = 1;
    if( ( n_a+2 ) >=0 && ( n_a+2 ) <= 9 && ( n_b+1 )>= 0 && ( n_b+1 ) <= 9)     dp[n_a+2][n_b+1] = 1;
    if( ( n_a+2 ) >=0 && ( n_a+2 ) <= 9 && ( n_b-1 )>= 0 && ( n_b-1 ) <= 9)     dp[n_a+2][n_b-1] = 1;
    if( ( n_a-2 ) >=0 && ( n_a-2 ) <= 9 && ( n_b+1 )>= 0 && ( n_b+1 ) <= 9)     dp[n_a-2][n_b+1] = 1;
    if( ( n_a-2 ) >=0 && ( n_a-2 ) <= 9 && ( n_b-1 )>= 0 && ( n_b-1 ) <= 9)     dp[n_a-2][n_b-1] = 1;
    // pv2d(dp);END;

    

    int temp_a = n_a, temp_b = n_b;
    while (temp_a >= 0 && temp_a <= 9 && temp_b >= 0 && temp_b <= 9 && (temp_a != k_a || temp_b != k_b)) {
        dp[temp_a][temp_b] = 1;
        temp_a++; temp_b++;
    }

    
    temp_a = n_a, temp_b = n_b;
    while (temp_a >= 0 && temp_a <= 9 && temp_b >= 0 && temp_b <= 9 && (temp_a != k_a || temp_b != k_b)) {
        dp[temp_a][temp_b] = 1;
        temp_a++; temp_b--;
    }
    temp_a = n_a, temp_b = n_b;
    while (temp_a >= 0 && temp_a <= 9 && temp_b >= 0 && temp_b <= 9 && (temp_a != k_a || temp_b != k_b)) {
        dp[temp_a][temp_b] = 1;
        temp_a--; temp_b++;
    }
    temp_a = n_a, temp_b = n_b;
    while (temp_a >= 0 && temp_a <= 9 && temp_b >= 0 && temp_b <= 9 && (temp_a != k_a || temp_b != k_b)) {
        dp[temp_a][temp_b] = 1;
        temp_a--; temp_b--;
    }


    temp_a = n_a, temp_b = n_b;
    while (temp_a >= 0 && temp_a <= 9 && temp_b >= 0 && temp_b <= 9 && (temp_a != k_a || temp_b != k_b)) {
        dp[temp_a][temp_b] = 1;
        temp_a--; 
    }
    temp_a = n_a, temp_b = n_b;
    while (temp_a >= 0 && temp_a <= 9 && temp_b >= 0 && temp_b <= 9 && (temp_a != k_a || temp_b != k_b)) {
        dp[temp_a][temp_b] = 1;
        temp_a++;
    }
    temp_a = n_a, temp_b = n_b;
    while (temp_a >= 0 && temp_a <= 9 && temp_b >= 0 && temp_b <= 9 && (temp_a != k_a || temp_b != k_b)) {
        dp[temp_a][temp_b] = 1;
        temp_b--;
    }
    temp_a = n_a, temp_b = n_b;
    while (temp_a >= 0 && temp_a <= 9 && temp_b >= 0 && temp_b <= 9 && (temp_a != k_a || temp_b != k_b)) {
        dp[temp_a][temp_b] = 1;
        temp_b++;
    }
    // pv2d(dp);


    vi2d check(10, vi(10,0));
    vi ans {0,0,0,0};
    For(i, 1, 9) {
        For(j, 1, 9) {
            if(i != n_a || j != n_b ) {
                int failed = 0;
                For(k, -1, 2) {
                    For(l, -1, 2) {
                        if( (i+k) == k_a && (j+l) == k_b) {
                            failed = 1;
                        }
                    }
                }
                if(failed == 0) {
                    int queen_in_king = 0;
                    For(k, -1, 2) {
                        For(l, -1, 2) {
                            if( (n_a+k) == k_a && (n_b+l) == k_b) {
                                queen_in_king = 1;
                            }
                        }
                    }
                    if(queen_in_king == 0) {
                        int can_eat = 0;
                        For(k, -1, 2) {
                            For(l, -1, 2) {
                                if( (i+k) == n_a && (j+l) == n_b) {
                                    // cout << "can_Eat : " << (i+k) << " , " << (j+l) << endl; 
                                    can_eat = 1;
                                }
                            }
                        }
                        if(can_eat == 1) {
                            check[i][j] = 1;
                            ans[1]++;
                            continue;
                        }
                    }


                    if(dp[i][j] == 1) {
                        if(check_surr(i,j,dp)) {
                            // cout << "check : " << i << ", " << j <<endl; 
                            check[i][j] = 1;
                            ans[1]++;
                        }
                        else {
                            // cout << "checkmate : " << i << ", " << j <<endl; 
                            ans[0]++;
                        }
                    }
                    else {
                        if(check_surr(i,j,dp)) {
                            // cout << "safe : " << i << ", " << j <<endl; 
                            ans[3]++;
                        }
                        else {
                            // cout << "stalemate : " << i << ", " << j <<endl; 
                            ans[2]++;
                        } 
                    }
                }
            }
        }
    }
    // pv2d(check);
    return ans;
}

int32_t main() {
    // system("clear");
    vi ans = ninjaChess2021("a1", "g5");
    pv(ans);
}