#include "bits/stdc++.h"
using namespace std;

int solve() {
    int n, k, d, mod = 1000000007; cin >> n >> k >> d;
    vector<long long> small(n + 1, 0), big(n + 1, 0);
    small[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = min(i, k); j > 0; --j) {
            if (j >= d) {
                big[i] += small[i - j] + big[i - j];
            } else {
                big[i] += big[i - j];
                small[i] += small[i - j];
            }
        }
        big[i] %= mod; small[i] %= mod;
    }
    return big[n];
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}