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
#define SPEED ios_base::sync_with_stdio(false)
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
#define deb(x) cout << '\t'<<#x << " = " << x << " ; "
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
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

int returnmax(int first, int last, vi &arr)
{
    int count = 0;
    int len = 0;
    int K = min(arr[first], arr[last]);
    int f = first+1, l = f+1;
    int anss=0, store_anss=INT_MIN;

    while(l < last && f < last) {
        while(arr[f] > arr[l] && l < last-1) {
            pl("1");
            l++;
        }
        deb(first); deb(last); deb(f); deb(l);
        anss = l-f+1;
        store_anss = max(anss, store_anss);
        f = l;
        l = l+1;
    }
 
    // For(i, first,last+1) {
    //     if (arr[i] < K) {
    //         count += 1;
    //     }
    //     else {
    //         len = max(len, count);
    //         count = 0;
    //     }
    // }
 
    // if (count) {
    //     len = max(len, count);
    // }
    // deb(first); deb(last); deb(len);END;
    return store_anss;
}

int MaxBridgeLength(int n, vi arr) {
    if(n < 4) {
        return 0;
    }
    int ans=0, store_ans = INT_MIN;
    int first = 0, i = 1, last = 1;
    while(last < n && first < n) {
        while(arr[first] > arr[last] && last < n-1) {
            last++;
        }
        ans = returnmax(first, last, arr);
        store_ans = max(ans, store_ans);
        first = last;
        last = last+1;
    }
    return store_ans;
}
// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the
// longest subarray with all elements
// smaller than K
int largestSubarray(int arr[], int N,
					int K)
{
	// Stores the length of maximum
	// consecutive sequence
	int count = 0;

	// Stores maximum length of subarray
	int len = 0;

	// Iterate through the array
	for (int i = 0; i < N; i++) {

		// Check if array element
		// smaller than K
		if (arr[i] < K) {
			count += 1;
		}
		else {

			// Store the maximum
			// of length and count
			len = max(len, count);

			// Reset the counter
			count = 0;
		}
	}

	if (count) {
		len = max(len, count);
	}

	// Print the maximum length
	cout << len;
}


void sol() {
    inpt(n); cinbuffer;
    vi arr = input1l();
    int a = MaxBridgeLength(arr.size(), arr);
    deb(a);END;
    return;
}

int32_t main() {
    SPEED1;
    inpt(t); 
    while(t--) {
        sol();
    }
}

/*

3
8
7 7 6 2 3 4 7 9
8
6 5 2 4 1 8 6 2
9
7 7 3 9 3 2 1 7 8

*/