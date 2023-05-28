#include "bits/stdc++.h"
using namespace std;

void subSolve(int n) {
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

void solve() {
    int n, k; cin >> n >> k;
    for (int i = k - 3; i > 0; --i) {
        printf("1 ");
    }
    subSolve(n - k + 3);
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}