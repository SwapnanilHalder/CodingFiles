#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

void swap(int &x1, int &x2) {
    x1 ^= x2;
    x2 ^= x1;
    x1 ^= x2;
}

void solve() {
    int x1,x2,x3,x4,y1,y2,y3,y4;
    cin >>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    if(x2>x1) swap(x1,x2);
    if(y2>y1) swap(y1,y2);
    if(x4>x3) swap(x3,x4);
    if(y4>y3) swap(y3,y4);
    int height1=0, width1=0;
    int area1 = (x1-x2)*(y1-y2);
    int area2 = (x3-x4)*(y3-y4);
    height1 = max(min( (x1-max(x2, x4)) , (x3-max(x2, x4)) ), 0);
    width1 = max(min( (y1-max(y2, y4)) , (y3-max(y2, y4)) ), 0);
    // height2 = max( (x1-min(x2, x4)) , (x3-min(x2, x4)) );
    // width2 = max( (y1-min(y2, y4)) , (y3-min(y2, y4)) );
    cout << height1*width1 << " " << (area1+area2-(height1*width1)) << endl;
}

signed main() {
    SPEED1;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int __t; cin >> __t; while(__t--)
    solve();
}