#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926536
#define MOD 1000000007
#define ll long long
#define END cout<<"\n"
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

void print2d (vector<vector<long>> &dp){
    END;END;END;
    for(const auto &v : dp) {
        for(const auto &i: v){
            cout<< i << " ";
        }
        END;
    }
}
long getWays(int n, vector<long> c) {
    sort(c.begin(), c.end());
    cout<< " C : "<<endl;
    for(auto &i: c){
        cout << i << " ";
    }END;
    long max = *max_element(c.begin(), c.end());
    vector<vector<long>> dp(max+1, vector<long>(n+1, 0));
    For(i, 0, n+1) {
        dp[0][i] = 0;
    }
    For(i, 0, c.size()){
        dp[c[i]][0] = 1;
    }

    For(i, 1, max+1) {
        For(j, 1, n+1) {
            if(find(c.begin(), c.end(), i) != c.end()){
                int v = j, u = 0; 
                int sum{0};
                while(v >= 0 and u <= i) {
                    sum += dp[u][v];
                    u++;
                    v--;
                }
                cout << "dp["<<i<<"]["<<j<<"] sum is :" << sum<<endl;
                dp[i][j] = sum;
            }
        }
    }
    print2d(dp);
    cout << max << "  " << n << endl;
    return dp[max][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c);

    fout << ways << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
