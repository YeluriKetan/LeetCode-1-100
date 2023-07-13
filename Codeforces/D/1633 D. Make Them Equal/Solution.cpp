#include "bits/stdc++.h"
using namespace std;
typedef vector<int> VI;

int solve(VI &minOper) {
    int n, k; cin >> n >> k;
    int maxK = min(12 * n, k);
    VI b(n), c(n), w(maxK + 1, 0);
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) {
        for (int j = maxK; j > -1; --j) {
            auto next = j + minOper[b[i]];
            if (next <= maxK) {
                w[next] = max(w[next], w[j] + c[i]);
            }
        }
    }
    return w[maxK];
}

int main() {
    ios::sync_with_stdio(false);
    VI minOper(1001, INT_MAX);
    minOper[1] = 0;
    for (int i = 1; i < 1000; ++i) {
        for (int j = 1; j <= i; ++j) {
            int k = i + i / j;
            if (k > 1000) continue;
            minOper[k] = min(minOper[k], minOper[i] + 1);
        }
    }
    int t; cin >> t;
    while (t--) cout << solve(minOper) << "\n";
    return 0;
}