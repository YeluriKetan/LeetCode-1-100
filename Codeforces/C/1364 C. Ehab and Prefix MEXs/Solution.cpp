#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), ans(n, -1);
    vector<bool> avoid(n + 1, false);
    cin >> a[0];
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        if (a[i] != a[i - 1]) {
            ans[i] = a[i - 1];
            avoid[a[i - 1]] = true;
        }
    }
    avoid[a[n - 1]] = true;
    for (int i = 0, p = 0; i < n; ++i) {
        if (ans[i] > -1) continue;
        while (avoid[p]) p++;
        ans[i] = p++;
    }
    for (auto curr: ans) {
        cout << curr << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}