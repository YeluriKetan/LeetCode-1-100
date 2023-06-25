#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n, k, currCount; cin >> n >> k;
    cout << (k % n ? 2 : 0) << "\n";
    for (int i = 0; i < n; ++i) {
        currCount = k / n + ((k % n) > i ? 1 : 0);
        for (int j = 0; j < max(0, i + currCount - n); ++j) cout << "1";
        for (int j = max(0, i + currCount - n); j < i; ++j) cout << "0";
        for (int j = i; j < min(i + currCount, n); ++j) cout << "1";
        for (int j = min(i + currCount, n); j < n; ++j) cout << "0";
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}