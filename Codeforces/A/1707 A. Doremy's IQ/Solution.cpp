#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n, q, nextQ = 1, ind; cin >> n >> q;
    vector<int> contests(n), ans(n, 0);
    for (int i = 0; i < n; ++i) cin >> contests[i];
    ans[n - 1] = 1;
    for (ind = n - 2; ind > -1; --ind) {
        if (contests[ind] > nextQ) {
            nextQ++;
        }
        if (nextQ <= q) {
            ans[ind] = 1;
        } else {
            break;
        }
    }
    for (; ind > -1; --ind) {
        if (contests[ind] <= q) {
            ans[ind] = 1;
        }
    }
    for (auto currChoice: ans) {
        cout << currChoice;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}