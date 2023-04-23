#include "bits/stdc++.h"
using namespace std;
using namespace std::chrono;

int solve() {
    int n, ai, s = 0, si, mx = 0, currS; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        s += ai;
        mx = max(mx, ai);
        v[i] = ai;
    }
    for (int i = s / mx; i > 1; --i) {
        si = s / i; currS = 0;
        for (int j = 0; j < n; ++j) {
            currS += v[j];
            if (currS == si) {
                currS = 0;
            } else if (currS > si) {
                break;
            }
        }
        if (currS == 0) { return n - i; }
    }
    return n - 1;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}