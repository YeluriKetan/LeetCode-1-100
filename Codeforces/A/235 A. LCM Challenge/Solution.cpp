#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll solve(ll n) {
    ll third, t;
    if (n < 3) return n;
    ll ans = n * (n - 1);
    if (n % 2) return ans * (n - 2);
    third = n / 2 - 1;
    for (ll i = n / 2; i <= n - 3; ++i) {
        t = i / gcd(n, i);
        t /= gcd(n - 1, t);
        third = max(third, t);
    }
    return max(ans * third, solve(n - 1));
}

int main() {
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    cout << solve(n) << "\n";
    return 0;
}