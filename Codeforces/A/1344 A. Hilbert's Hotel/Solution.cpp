#include "bits/stdc++.h"
using namespace std;

string solve() {
    int n, ai, t; cin >> n;
    vector<bool> m(n, false);
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        t = ((i + ai) % n + n) % n;
        if (m[t]) {
            ans = false;
        } else {
            m[t] = true;
        }
    }
    return ans ? "YES" : "NO";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}