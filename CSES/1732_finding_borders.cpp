#include <bits/stdc++.h>
using namespace std;

const int BASE = 31;
const int MOD = 1e9 + 7;



pair<vector<int>, vector<int>> computePrefixHashes(const string &s) {
    int n = s.size();
    vector<int> prefix(n + 1, 0);
    vector<int> power(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        power[i] = (1LL * power[i - 1] * BASE) % MOD;
        prefix[i] = (1LL * prefix[i - 1] * BASE + (s[i - 1] - 'a' + 1)) % MOD;
    }
    return {prefix, power};
}

vector<int> findBorderLengths(const string &s) {
    auto [prefix, power] = computePrefixHashes(s);
    int n = s.size();
    vector<int> borders;
    for (int l = 1; l < n; ++l) {
        int prefixHash = prefix[l];
        int suffixHash = (prefix[n] - 1LL * prefix[n - l] * power[l] % MOD + MOD) % MOD;
        if (prefixHash == suffixHash) {
            borders.push_back(l);
        }
    }
    return borders;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<int> borders = findBorderLengths(s);
    for (int len : borders) {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}