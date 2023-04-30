#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n; cin >> n;
    if (n < 4) {
        cout << -1 << "\n";
        return;
    }
    for (int i = (n / 2) * 2; i > 4; i -= 2) {
        cout << i << " ";
    }
    cout << "2 4 ";
    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}