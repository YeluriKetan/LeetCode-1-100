#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    ll l, r, ans = 1; cin >> l >> r;
    if (l == r) return 0;
    while (l != r) {
        l >>= 1;
        r >>= 1;
        ans <<= 1;

    }
    return ans - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}