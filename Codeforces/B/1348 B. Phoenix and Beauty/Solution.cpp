#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, ai; cin >> n >> k;
    unordered_set<int> countUniq;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        countUniq.insert(ai);
    }
    if (countUniq.size() > k) {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= n && countUniq.size() < k; ++i) {
        countUniq.insert(i);
    }
    cout << k * n << "\n";
    string ans;
    for (auto curr: countUniq) {
        ans += to_string(curr) + " ";
    }
    while (n--) {
        cout << ans;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
