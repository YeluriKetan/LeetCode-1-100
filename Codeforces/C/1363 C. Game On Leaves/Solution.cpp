#include "bits/stdc++.h"
using namespace std;

string solve() {
    int n, x, u, v, c = 0; cin >> n >> x;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        if (u == x || v == x) c++;
    }
    if (c <= 1) {
        return "Ayush";
    } else {
        if (n % 2) {
            return "Ashish";
        } else {
            return "Ayush";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}