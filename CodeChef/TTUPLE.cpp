#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
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
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << #x << "=" << x << endl
#define pl(x) cout << x << endl
using namespace std;

int ans{3};
int step{0};

vi input1l(){
    vi input(0);
    string str, num;
    getline(cin, str);
    stringstream X(str);
    while(getline(X, num, ' ')) {
        input.pb(stoi(num));
    }
    //pv(input);
    return input;
}

void pv3d(vector<vector<vector<int>>> &bt) {
	cout<<endl <<"Content of 3D Vector: "<<endl;
	For(i, 0, bt.size()){
		For(j, 0, bt[i].size()){
			For(k, 0, bt[i][j].size()){
				cout<<bt[i][j][k]<<' ';
			}
			cout<<endl;
		}	
		cout<<endl;
	}
}

void backtrack(vector<vector<vector<int>>> &bt, vi &p, vi &q) {
    // if(bt.size() == 0) {
    //     pl(ans);
    //     return;
    // }
    // For(i, 0, bt.size()) {
    //     if(bt[i][0] == vi{1, 0}) {
    //         cout << "END"<<endl;
    //         ans--;
    //         bt.erase(bt.begin() + i);
    //         i--;
    //     }
    // }
    // deb(ans);
    // pl(bt.size());
    // For(i, 0, bt[0].size()) {
    //     for(int )
    //     if( (bt[1][i][1] < bt[0][i][1]) ||  (bt[2][i][1] < bt[0][i][1]) ) continue;
    //     if( (bt[1][i][1] == bt[0][i][1]) ||  (bt[2][i][1] == bt[0][i][1]) ) {
    //         if (bt[1][i][1] == bt[0][i][1]) {
    //             if (bt[2][i][1] == bt[0][i][1]) {
    //                 bt[1][i][1] = 0;
    //                 bt[2][i][1] = 0;
    //             } else bt[1][i][1] = 0;
    //         } else bt[2][i][1] = 0;
    //     }
    // }
    //pv3d(bt);

    //backtrack(bt, p, q);
    int i=0,j=0,k=0;
    while(i < bt[0].size() && j < bt[1].size() && k < bt[2].size() ) {
        if( bt[1][j][1] > bt[0][i][1] ) j++;
        if( bt[2][k][1] > bt[0][i][1] ) k++;
        
        if( bt[1][j][1] == bt[0][i][1] ) {
            if( bt[2][k][1] == bt[0][i][1] ) {
                bt[0][i][1] = bt[2][k][1] = bt[1][j][1] = 0;
                step++; break;
            } else {
                bt[0][i][1] = bt[1][j][1] = 0;
                step++; break;              
            }
        } else if( bt[2][k][1] == bt[0][i][1] ) {
            bt[0][i][1] = bt[2][k][1] = 0;
            step++; break;
        }
        i++;
    }
    //pv3d(bt);
    deb(step);
}

void solution(vi &p, vi &q) {
    vector<vector<vector<int>>> bt(p.size(), vi2d(0, vi(2,0)));
    For(i, 0, p.size()) {
        int mult = 1;
        while( (p[i] * mult) <= q[i]) {
            bt[i].pb(vi{mult, (q[i] - (p[i]*mult)) });
            mult++;
        }

    }

    pv3d(bt);
    backtrack(bt, p, q);
}

int main() {
    int t{0};
    cin >> t ;
    cinbuffer;
    while(t--) {
        vi p = input1l();
        vi q = input1l();
        solution(p, q);
    }
    
}