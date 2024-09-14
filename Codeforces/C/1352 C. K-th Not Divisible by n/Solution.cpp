#include "bits/stdc++.h"
using namespace std;

int solve() {
    int n, k; cin >> n >> k;
    int factor = k / (n - 1);
    return k % (n - 1) ? factor * n + k % (n - 1) : factor * n - 1;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}