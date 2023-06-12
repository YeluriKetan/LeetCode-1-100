#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    ll n, maxProd = 0, maxGain = 0; cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        maxProd += a[i] * b[i];
    }
    for (int i = 0; i < n; ++i) {
        ll l = i - 1, r = i + 1, currGain = 0;
        while (l > -1 && r < n) {
            currGain += (a[l] - a[r]) * (b[r] - b[l]);
            maxGain = max(maxGain, currGain);
            l--; r++;
        }
    }
    for (int i = 0; i < n; ++i) {
        ll l = i, r = i + 1, currGain = 0;
        while (l > -1 && r < n) {
            currGain += (a[l] - a[r]) * (b[r] - b[l]);
            maxGain = max(maxGain, currGain);
            l--; r++;
        }
    }
    return maxProd + maxGain;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}