#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n, c = 0, aC = 0, bC = 0; cin >> n;
    string s, a(n, '('), b(n, '('); cin >> s;
    bool ans = true;
    for (auto curr: s) if (curr == '0') c++;
    if (c % 2) ans = false;
    for (int i = 0; i < n && ans; ++i) {
        auto curr = s[i];
        if (curr == '1') {
            if (c) {
                if ((aC > 0 && bC > 0) && (aC > 1 || bC > 1)) {
                    aC--; bC--;
                    a[i] = b[i] = ')';
                } else {
                    aC++; bC++;
                }
            } else {
                if (aC & bC) {
                    aC--; bC--;
                    a[i] = b[i] = ')';
                } else {
                    aC++; bC++;
                }
            }
        } else {
            if (!(aC || bC)) {
                ans = false;
            } else if (aC >= bC) {
                aC--; bC++;
                a[i] = ')';
            } else {
                aC++; bC--;
                b[i] = ')';
            }
            c--;
        }
    }
    if (aC != 0 || bC != 0) ans = false;
    if (ans) {
        cout << "YES\n" << a << "\n" << b << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
