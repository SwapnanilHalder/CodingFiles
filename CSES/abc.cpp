#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(int idx, ll* arr, ll sum1, ll sum2, ll N)
{
    // If we have reached the end, return the difference
    // between the sums
    if (idx == N) {
        return abs(sum1 - sum2);
    }

    // Choose the current apple in group 1
    ll choose
        = solve(idx + 1, arr, sum1 + arr[idx], sum2, N);

    // Choose the current apple in group 2
    ll notChoose
        = solve(idx + 1, arr, sum1, sum2 + arr[idx], N);

    // Return the minimum of both the choices
    return min(choose, notChoose);
}

int main()
{
    // Sample Input
    ll N = 20;
    ll arr[] = { 314836307, 815098885 ,922742346 ,53006071 ,757943472, 481505203 ,354207278 ,175676232, 335088325, 921705085 ,231986392, 619406418, 170606376 ,498080884, 415616625, 40905556, 110076295 ,642911923, 932231564, 381545587 };

    // Call the recursive function to find the minimum
    // difference between both the groups
    ll ans = solve(0, arr, 0, 0, N);
    cout << ans;
}