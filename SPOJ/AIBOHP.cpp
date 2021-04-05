/*
BuggyD suffers from AIBOHPHOBIA - the fear of Palindromes. A palindrome is a string that reads the same forward and backward.

To cure him of this fatal disease, doctors from all over the world discussed his fear and decided to expose him to large number of palindromes. To do this, they decided to play a game with BuggyD. The rules of the game are as follows:

BuggyD has to supply a string S. The doctors have to add or insert characters to the string to make it a palindrome. Characters can be inserted anywhere in the string.

The doctors took this game very lightly and just appended the reverse of S to the end of S, thus making it a palindrome. For example, if S = "fft", the doctors change the string to "ffttff".

Nowadays, BuggyD is cured of the disease (having been exposed to a large number of palindromes), but he still wants to continue the game by his rules. He now asks the doctors to insert the minimum number of characters needed to make S a palindrome. Help the doctors accomplish this task.

For instance, if S = "fft", the doctors should change the string to "tfft", adding only 1 character.

Input
The first line of the input contains an integer t, the number of test cases. t test cases follow.

Each test case consists of one line, the string S. The length of S will be no more than 6100 characters, and S will contain no whitespace characters.

Output
For each test case output one line containing a single integer denoting the minimum number of characters that must be inserted into S to make it a palindrome.
*/

#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926536
#define MAX 1000005
#define int long long
#define END cout<<"\n"
using namespace std;

void print(vector<vi> &matrix){
    for ( const auto &row : matrix ) {
        for ( const auto &s : row ) cout << s << ' ';
        END;
    }
}

int lcs(string &s) {
    int len = s.length();
    vector<vector<int>> matrix(len+1, vi(len+1, 0));
    string rev = s;
    reverse(rev.begin(), rev.end());
    For(i, 0, len){
        For(j, 0, len) {
            if (s[i] == rev[j]){
                matrix[i+1][j+1] = matrix[i][j] + 1;
            }
            else {
                matrix[i+1][j+1] = max(matrix[i][j+1], matrix[i+1][j]);
            }
        }
    }
    //print(matrix);
    return matrix[len][len];
}

int32_t main() {
    SPEED;
    int t;
    cin >> t;
    For(l, 0, t){
        string s;
        cin >> s;
        int LCS = lcs(s);
        cout << s.length() - LCS;
        END;
    }
}