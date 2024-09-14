#include "bits/stdc++.h"
using namespace std;

int solve() {
    int l, r, ans = 1, count = 0;
    cin >> l >> r;
    while (ans <= r) {
        ans <<= 1;
        count++;
    }
    return count - 1;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}