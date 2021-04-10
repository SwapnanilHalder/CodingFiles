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


#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define li list<int>
#define mii map<int, int>
#define msi map<string, int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.14159265358979323846
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END


using namespace std;


vector<int> ninjaChess2021(string king, string ninja) {

    int k_a{0}, k_b{0} ,n_a{0}, n_b{0};
    k_a = king[0] - 'a' + 1;
    k_b = king[1] - '0';
    n_a = ninja[0] - 'a' + 1;
    n_b = ninja[1] - '0';
    // deb(k_a);deb(k_b);deb(n_a);deb(n_b);
    
    vector<vector<int>> dp(10, vi(10,0));
    
    for(int i{0}; i<10; i++) {
        for(int j{0}; j<10; j++) {
            if(i== 0 || j== 0 || i == 9|| j == 9) {
                dp[i][j] = 1;
            }
        }
    }
    
    for(int i = k_a-1; i<k_a+2; i++) {
        for(int j = k_b-1; j<k_b+2; j++) {
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


    // vi2d check(10, vector<int>(10,0));
    vector<int> ans {0,0,0,0};
    for(int i = 1; i<9; i++) {
        for(int j = 1; j<9; j++) {
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
                            // check[i][j] = 1;
                            ans[1]++;
                            continue;
                        }
                    }


                    if(dp[i][j] == 1) {

                        int failed = 0;
                        For(k, -1, 2) {
                            For(l, -1, 2) {
                                if(k != 0 || l!= 0) {
                                    if(dp[i+k][j+l] == 0) {
                                        // cout <<"nooo : "<< i+k << " & " << j+l << endl;
                                        failed = 1;
                                    }
                                }
                            }
                        }

                        if(failed == 1) {
                            // cout << "check : " << i << ", " << j <<endl; 
                            // check[i][j] = 1;
                            ans[1]++;
                        }
                        else {
                            // cout << "checkmate : " << i << ", " << j <<endl; 
                            ans[0]++;
                        }
                    }
                    else {

                        int failed = 0;
                        For(k, -1, 2) {
                            For(l, -1, 2) {
                                if(k != 0 || l!= 0) {
                                    if(dp[i+k][j+l] == 0) {
                                        // cout <<"nooo : "<< i+k << " & " << j+l << endl;
                                        failed = 1;
                                    }
                                }
                            }
                        }

                        if(failed == 1) {
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
    vector<int> ans = ninjaChess2021("a1", "g5");
    pv(ans);
}