#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    ll x, y, n; cin >> x >> y;
    return (x > y) ? x + y : y - (y % x) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}