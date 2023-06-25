#include "bits/stdc++.h"
using namespace std;

int solve() {
    int n, m, ans = 0; cin >> n >> m;
    vector<int> a(n), b(m);
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
        int gMax = -1, gMaxJ = -1, lMin, t;
        for (int j = 0; j < n; ++j) {
            if (used[j]) continue;
            lMin = INT_MAX;
            for (int k = 0; k < m; ++k) {
                t = a[j] & b[k];
                lMin = min(lMin, t - (t & ans));
            }
            if (lMin > gMax) {
                gMax = lMin;
                gMaxJ = j;
            }
        }
        used[gMaxJ] = true;
        ans |= gMax;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}