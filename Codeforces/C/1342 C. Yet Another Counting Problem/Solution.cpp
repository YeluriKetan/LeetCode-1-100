#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> VLL;

ll count(ll a, ll b, ll l, ll r, vector<VLL> &modCycle, ll mN) {
    if (a == b) return 0;
    ll ans = 0, t, ni, d;
    for (ll i = l; i <= min(r, l + b - 1); ++i) {
        t = (i % b) % a;
        ni = ceil((r - i + 1) / (double) b);
        d = i % a;
        for (auto curr: modCycle[(t - d + a) % a]) {
            ans += ni / mN;
            if (curr <= ni % mN) ans++;
        }
    }
    return r - l + 1 - ans;
}

void solve() {
    ll a, b, q, li, ri, mN = 1; cin >> a >> b >> q;
    if (a > b) swap(a, b);
    vector<VLL> modCycle(a, VLL());
    vector<bool> seen(a, false);
    for (ll m = 0; !seen[m]; m = (m + b) % a, mN++) {
        modCycle[m].push_back(mN);
        seen[m] = true;
    }
    while (q--) {
        cin >> li >> ri;
        cout << count(a, b, li, ri, modCycle, mN - 1) << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}