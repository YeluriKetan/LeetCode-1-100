#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    ll n, mod = 1, count = 0; cin >> n;
    for (ll i = 1; i < n; ++i) {
        if (gcd(n, i) == 1) {
            mod = (mod * i) % n;
            count++;
        }
    }
    if (mod == 1) {
        mod = 0;
    } else {
        count--;
    }
    cout << count << "\n";
    for (ll i = 1; i < n; ++i) {
        if (gcd(n, i) == 1 && i != mod) cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}