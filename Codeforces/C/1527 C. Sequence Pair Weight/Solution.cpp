#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    ll n, ai, ans = 0; cin >> n;
    map<ll, ll> preSum;
    for (int i = 1; i <= n; ++i) {
        cin >> ai;
        auto it = preSum.emplace(ai, 0);
        ans += it.first->second * (n - i + 1);
        it.first->second += i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}