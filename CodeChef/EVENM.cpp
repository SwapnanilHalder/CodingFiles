#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<lli>
#define vi2d vector<vector<int>> 
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define ll long long
#define lli long long int
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define deb(x) cout << #x << "=" << x << endl
#define pl(x) cout << x << endl
using namespace std;

int main() {
    SPEED;
    int t{0};
    cin >> t;
    while(t--) {
        int n{0}; cin >> n; int n2 = n*n;
        vi row(n, 1);
        For(i, 1, row.size()) {
            row[i] += row[i-1];
        }
        if(n & 1 == 1) {
            For(i, 0, n) {
                For(j, 0, n) {
                    cout << row[j] << " ";
                    row[j] += n;
                }
                END;
            }
        } else {
            For(i, 0, n) {
                For(j, 0, n) {
                    cout << row[j] << " ";
                    row[j] += n;
                }
                END;
                reverse(row.begin(), row.end());
            }
        }
    }
}