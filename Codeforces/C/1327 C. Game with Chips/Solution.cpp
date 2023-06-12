#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n, m, k, t; cin >> n >> m >> k;
    for (int i = 0; i < 2 * k; ++i) cin >> t >> t;
    cout << n + m - 3 + m * n << "\n";
    cout << string(n - 1, 'U') << string(m - 1, 'L');
    for (int i = 0; i < n - 1; ++i) {
        cout << string(m - 1, i % 2 ? 'L' : 'R') << 'D';
    }
    cout << string(m - 1, (n - 1) % 2 ? 'L' : 'R') << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
