#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    ll n, lcm; cin >> n;
    vector<ll> a(n);
    unordered_set<ll> lastDiv;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    lcm = a[0] * a[n - 1];
    for (int i = sqrt(a[0]); i > 1; --i) {
        if (a[0] % i == 0) return -1;
    }
    for (int i = 2; i <= a[n - 1] / 2; ++i) {
        if (a[n - 1] % i == 0) {
            lastDiv.insert(i);
            lastDiv.insert(i * a[0]);
        }
    }
    lastDiv.insert(a[n - 1]);
    lastDiv.insert(a[0]);
    if (lastDiv.size() != a.size()) return -1;
    for (auto currD: a) {
        if (lastDiv.find(currD) == lastDiv.end()) return -1;
    }
    return lcm;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
