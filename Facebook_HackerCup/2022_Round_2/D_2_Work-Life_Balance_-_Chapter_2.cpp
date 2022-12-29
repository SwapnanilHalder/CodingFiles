#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define flash ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mod 1000000007

void build(ll ind, ll low, ll high, vector<ll>& seg, vector<ll>& a){
    if(low == high){
        seg[ind] = a[low];
        return;
    }

    ll mid = low + (high - low)/2;
    build(2*ind+1, low, mid, seg, a);
    build(2*ind+2, mid+1, high, seg, a);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

ll query(ll ind, ll low, ll high, vector<ll>& seg, vector<ll>& a, ll left, ll right){
    if(low == left && high == right){
        return seg[ind];
    }

    if(left > high || right < low){
        return 0;
    }

    ll mid = low + (high - low)/2;
    if(high <= mid)
        return query(2*ind+1, low, mid, seg, a, left, right);
    else if(low > mid)
        return query(2*ind+2, mid+1, high, seg, a, left, right);
    else{
        ll num1 = query(2*ind+2, low, mid, seg, a, left, mid);
        ll num2 = query(2*ind+2, mid+1, high, seg, a, mid+1, right);
        return (num1 + num2);
    }
}

void update(ll idx, ll low, ll high, ll ind, ll val, vector<vector<ll>>& seg, vector<ll>& a){
    if(low == high && low == ind)
        seg[idx] = val;

    ll mid = low + (high - low)/2;
    if(ind <= mid)
        update(2*idx+1, low, mid, ind, val, seg, a);
    else
        update(2*idx+2, mid+1, high, ind, val, seg, a);

    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), seg(4*n+1, 0);
    for(ll i=0; i<n; i++)    cin >> a[i];

    build(0, 0, n-1, seg, a);
    ll score = 0;

    while(m--){
        ll x, y, z;
        cin >> x >> y >> z;
        z--

        update(0, 0, n-1, x-1, y, seg, a);
        ll left = query(0, 0, n-1, seg, a, 0, z);
        ll right = query(0, 0, n-1, seg, a, z+1, n-1);

        if(abs(right - left)&1)
            score--;
    }
}

int main(){
    flash;

    freopen("perfectly_balanced_chapter_1_input.txt","r",stdin);
    freopen("output2.txt","w",stdout);

    int t, num = 1;
    cin >> t;

    while(num <= t)
        cout << "Case #" << num << ": ", solve(), num++;

    return 0;
}

