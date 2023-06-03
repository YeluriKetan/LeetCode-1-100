#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    ll n, s = 0, currDiff = 0, prevMin = 0, currMax = 0; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i % 2 == 0) s += a[i];
    }
    for (int i = 1; i < n; i += 2) {
        currDiff += a[i] - a[i - 1];
        currMax = max(currMax, currDiff - prevMin);
        prevMin = min(prevMin, currDiff);
    }
    prevMin = currDiff = 0;
    for (int i = 2; i < n; i += 2) {
        currDiff += a[i - 1] - a[i];
        currMax = max(currMax, currDiff - prevMin);
        prevMin = min(prevMin, currDiff);
    }
    return s + currMax;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}