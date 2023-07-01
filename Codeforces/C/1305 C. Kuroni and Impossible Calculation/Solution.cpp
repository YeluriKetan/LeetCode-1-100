#include "bits/stdc++.h"
using namespace std;

int powMod(int base, int pow, int mod) {
    int result = 1, currPow = base;
    while (pow) {
        if (pow & 1) {
            result = (result * currPow) % mod;
        }
        pow >>= 1;
        currPow = (currPow * currPow) % mod;
    }
    return result;
}

int solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), modCount(m, 0), diffCount(m, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    for (auto curr: a) {
        curr %= m;
        if (modCount[curr] > 0) {
            return 0;
        }
        for (int i = 0; i < m; ++i) {
            if (i <= curr) {
                diffCount[curr - i] += modCount[i];
            } else {
                diffCount[curr + m - i] += modCount[i];
            }
        }
        modCount[curr % m]++;
    }
    int ans = 1;
    for (int i = 0; i < m; ++i) {
        ans = (ans * powMod(i, diffCount[i], m)) % m;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}