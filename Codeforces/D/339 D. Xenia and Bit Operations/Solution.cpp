#include "bits/stdc++.h"
using namespace std;
typedef vector<int> VI;

void solve() {
    int n, m, temp, pi, bi; cin >> n >> m;
    vector<VI> seq(n + 1, VI());
    for (int i = 1 << n; i > 0; i--) {
        cin >> temp;
        seq[0].push_back(temp);
    }
    bool operIsOr = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 1 << (n - i); j++) {
            seq[i].push_back(operIsOr
                ? seq[i - 1][j * 2] | seq[i - 1][j * 2 + 1]
                : seq[i - 1][j * 2] ^ seq[i - 1][j * 2 + 1]);
        }
        operIsOr = !operIsOr;
    }
    for (int i = 0; i < m; ++i) {
        cin >> pi >> bi;
        operIsOr = true;
        pi--;
        seq[0][pi] = bi;
        for (int j = 1; j <= n; j++) {
            pi = pi / 2;
            seq[j][pi] = operIsOr
                ? seq[j - 1][pi * 2] | seq[j - 1][pi * 2 + 1]
                : seq[j - 1][pi * 2] ^ seq[j - 1][pi * 2 + 1];
            operIsOr = !operIsOr;
        }
        cout << seq[n][0] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}