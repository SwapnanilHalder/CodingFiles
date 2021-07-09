

#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define For(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) cout << i << " "; cout<<"\n"
#define pv2d(k) for(const auto &j: k) pv(j); cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;


/*
 * Complete the 'longestCommonSubsequence' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    vector<vector<int>> dp(a.size()+1, vector<int> (b.size()+1, 0));
    for(int i=1; i< a.size()+1; i++) {
        for(int j=1; j<= b.size(); j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    vector<int> ans;
    int x=a.size(), y=b.size();
    while (dp[x][y] != 0) {
        if(a[x-1] == b[y-1]) {
            ans.push_back(a[x-1]);
            x--; y--;
        }
        else {
            if(dp[x][y-1] > dp[x-1][y]) {
                y--;
            }
            else {
                x--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vi ans = longestCommonSubsequence(vi {1,2,3,4,1}, vi {3,4,1,2,1,3});
    pv(ans);
}



// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string first_multiple_input_temp;
//     getline(cin, first_multiple_input_temp);

//     vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

//     int n = stoi(first_multiple_input[0]);

//     int m = stoi(first_multiple_input[1]);

//     string a_temp_temp;
//     getline(cin, a_temp_temp);

//     vector<string> a_temp = split(rtrim(a_temp_temp));

//     vector<int> a(n);

//     for (int i = 0; i < n; i++) {
//         int a_item = stoi(a_temp[i]);

//         a[i] = a_item;
//     }

//     string b_temp_temp;
//     getline(cin, b_temp_temp);

//     vector<string> b_temp = split(rtrim(b_temp_temp));

//     vector<int> b(m);

//     for (int i = 0; i < m; i++) {
//         int b_item = stoi(b_temp[i]);

//         b[i] = b_item;
//     }

//     vector<int> result = longestCommonSubsequence(a, b);

//     for (size_t i = 0; i < result.size(); i++) {
//         fout << result[i];

//         if (i != result.size() - 1) {
//             fout << " ";
//         }
//     }

//     fout << "\n";

//     fout.close();

//     return 0;
// }

// string ltrim(const string &str) {
//     string s(str);

//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//     );

//     return s;
// }

// string rtrim(const string &str) {
//     string s(str);

//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//         s.end()
//     );

//     return s;
// }

// vector<string> split(const string &str) {
//     vector<string> tokens;

//     string::size_type start = 0;
//     string::size_type end = 0;

//     while ((end = str.find(" ", start)) != string::npos) {
//         tokens.push_back(str.substr(start, end - start));

//         start = end + 1;
//     }

//     tokens.push_back(str.substr(start));

//     return tokens;
// }
