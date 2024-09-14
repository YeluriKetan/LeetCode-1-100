#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    ll c, t, h; cin >> h >> c >> t;
    if (t <= (c + h) / 2) return 2;
    ll x = (h - t) / (2 * t - c - h);
    double xVal = (double) (c * x + h * x + h) / (double) (2 * x + 1) - t;
    double xVal1 = (double) (c * (x + 1) + h * (x + 1) + h) / (double) (2 * x + 3) - t;
    return (abs(xVal) <= abs(xVal1)) ? 2 * x + 1 : 2 * x + 3;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}

