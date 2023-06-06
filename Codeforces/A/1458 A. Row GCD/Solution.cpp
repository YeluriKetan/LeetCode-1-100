#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b > a) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    ll n, m, a1, ap, ai, bi, currGCD; cin >> n >> m >> a1;
    if (n == 1) {
        for (int i = 0; i < m; ++i) {
            cin >> bi;
            cout << a1 + bi << " ";
        }
        cout << "\n";
        return;
    }
    cin >> ai;
    currGCD = abs(ai - a1);
    ap = ai;
    for (int i = 2; i < n; ++i) {
        cin >> ai;
        currGCD = gcd(currGCD, abs(ai - ap));
        ap = ai;
    }
    for (int i = 0; i < m; ++i) {
        cin >> bi;
        cout << gcd(currGCD, a1 + bi) << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}