#include <iostream>
#include <sstream>
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
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;
int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}

vector<vector <int> >subarrays;
void generateSubArrays(vector<int> arr, int start, int end){

    vector <int> subarray;
    if (end == arr.size() )
        return;
    else if (start > end)
        generateSubArrays(arr, 0, end + 1);
    else
    {
        for (int i = start; i < end; i++ ) {
            subarray.push_back(arr[i]);
        }
        subarray.push_back(arr[end]);
        subarrays.push_back(subarray);
        generateSubArrays(arr, start +1, end);
    }
    return;
}

int bioHazard(int n, vector<int> allergic, vector<int> poisonous) {
    int ans = 0;
    generateSubArrays(allergic, 0, 0);
    for(int i = 0; i < subarrays.size(); ++i) {
        int c = 0;
        for(int j = 0; j < poisonous.size(); ++j ) {
            auto it = find(subarrays[i].begin(), subarrays[i].end(), poisonous[j]);
            if(it == subarrays[i].end() ) {
                ++c;
            }
        }
        if(c == 0 || c == subarrays[i].size() ) {
            ++ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> allergic = {2, 1, 3};
    vector<int> poisonous = {3, 3, 1};
    cout << bioHazard(3, allergic, poisonous) << endl;
    return 0;
}