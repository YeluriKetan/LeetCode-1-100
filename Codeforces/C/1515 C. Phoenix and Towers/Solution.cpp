#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> II;

void solve() {
    int n, m, x, hi, ti = 1, d = 1; cin >> n >> m >> x;
    vector<II> h(n);
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> hi;
        h[i] = {hi, i};
    }
    sort(h.begin(), h.end(), [](auto x, auto y) { return x.first > y.first; });
    for (auto [hi, i]: h) {
        t[i] = ti;
        if (ti == m && d == 1) {
            ti = m + 1; d = -1;
        } else if (ti == 1 && d == -1) {
            ti = 0; d = 1;
        }
        ti += d;
    }
    cout << "YES\n";
    for (auto ti: t) cout << ti << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}