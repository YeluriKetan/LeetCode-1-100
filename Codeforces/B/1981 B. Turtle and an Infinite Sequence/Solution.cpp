#include "bits/stdc++.h"
using namespace std;

int solve() {
    int n, m; cin >> n >> m;
    int l = n + m, r = max(0, n - m), ans = 0, currPow = 1;
    for (int i = 0; i <= 31; i++) {
        if ((l / currPow != r / currPow) || (l / currPow & 1)) {
            ans += currPow;
        }
        currPow <<= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}