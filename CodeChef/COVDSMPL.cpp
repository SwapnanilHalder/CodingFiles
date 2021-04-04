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

void solution(vi &input, vi2d &matrix) {
    For(i, 0, input[0]) {
        For(j, 0, input[0]) {
            printf("%d %d %d %d %d\n", 1, i+1,j+1,i+1,j+1);
            int num{0};
            cin >> num;
            matrix[i][j] = num;
        }
    }
}

int main() {
    int t{0};
    cin >> t;
    cinbuffer;
    while(t--) {
        vi input = input1l();
        vi2d matrix(input[0], vi(input[0],0));
        //pv2d(matrix);
        solution(input, matrix);
        cout << "2"<<endl;
        //for(const auto &v : matrix) {for(const auto &i: v){cout<<i<<" ";}END;}cout<<"";
        pv2d(matrix);
        int succeed{0};
        cin >> succeed;
        if(succeed == -1){
            return 0;
        } else {
            cinbuffer;
        }
    }
}