#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define END cout << "\n" 
#define ENDstd printf("\n")
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END

using namespace std;

class Solution {
public:
    void finalPrice(vector<int> prices) {
        int n = prices.size();
        vector<int> next_lesser;
        vector<int> final_price(n, 0);
        vector<int> full_price;
        stack<int> s;
        for(int i=n-1; i>=0; i++) {
            while(!s.empty() && s.top() > prices[i] ) {
                s.pop();
            }
            if(!s.empty()) {
                final_price[i] = prices[i] - s.top();
            } else {
                final_price[i] = prices[i];
                full_price.push_back(i);
            }
            s.push(prices[i]);  
        }
        long long total_price = accumulate(final_price.begin(), final_price.end(), 0);
        cout << total_price << endl;
        
        sort(full_price.begin(), full_price.end());
        for(auto &x: full_price) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
};


int main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution mySolution;
    string s; cin >> s;
    int k; cin >> k;

    cout << mySolution.kDistinctChar(s, k) << endl;
}