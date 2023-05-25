#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    ll x1, y1, x2, y2, dx, dy;
    cin >> x1 >> y1 >> x2 >> y2;
    dx = x2 - x1;
    dy = y2 - y1;
    return (dx * dy) ? dx * dy + 1 : 1;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
