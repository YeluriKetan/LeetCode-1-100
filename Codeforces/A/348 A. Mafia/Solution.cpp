#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    ll n, operCount = 0; cin >> n;
    vector<ll> plays(n);
    for (int i = 0; i < n; ++i) cin >> plays[i];
    sort(plays.begin(), plays.end());
    ll highest = plays[n - 1];
    for (int i = 0; i < n; ++i) {
        ll currOper = highest - max(plays[i] - operCount, 0LL);
        operCount += currOper;
        highest -= currOper;
    }
    return operCount + (ll) ceil((double) (highest * n) / (double) (n - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}