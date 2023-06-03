#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

void solve() {
    ll n, t; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << "1 " << n << "\n";
    for (int i = 0; i < n - 1; ++i) {
        t = a[i] % (n - 1);
        cout << -t * n << " ";
        a[i] = a[i] - t * n;
    }
    cout << "0\n1 " << max(n - 1, 1LL) << "\n";
    for (int i = 0; i < n - 1; ++i) {
        cout << - a[i] << " ";
    }
    cout << ((n == 1) ? "0" : "") << "\n" << n << " " << n << "\n" << -a[n - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
