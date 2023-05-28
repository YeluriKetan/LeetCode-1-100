#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    if (n % 2) {
        printf("%d %d %d\n", n / 2, n / 2, 1);
    } else {
        if (n % 4) {
            printf("%d %d %d\n", n / 2 - 1, n / 2 - 1, 2);
        } else {
            printf("%d %d %d\n", n / 2, n / 4, n / 4);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}