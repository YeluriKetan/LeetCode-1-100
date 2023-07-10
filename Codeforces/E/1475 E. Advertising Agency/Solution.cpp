#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define MOD 1000000007

int divideAndCount(int &n, int p) {
    int c = 0;
    while (n % p == 0) {
        c++;
        n /= p;
    }
    return c;
}

int powMod(int base, int pow) {
    ll currPow = base, ans = 1;
    while (pow) {
        if (pow & 1) {
            ans = (ans * currPow) % MOD;
        }
        currPow = (currPow * currPow) % MOD;
        pow >>= 1;
    }
    return ans;
}

int nCr(int n, int r) {
    if (n - r < r) {
        return nCr(n, n - r);
    }
    vector<int> factors(n + 1, 0);
    for (int i = n - r + 1; i <= n; ++i) {
        auto temp = i;
        factors[2] += divideAndCount(temp, 2);
        for (int j = 3; j <= temp; ++j) factors[j] += divideAndCount(temp, j);
    }
    for (int i = 1; i <= r; ++i) {
        auto temp = i;
        factors[2] -= divideAndCount(temp, 2);
        for (int j = 3; j <= temp; ++j) factors[j] -= divideAndCount(temp, j);
    }
    ll ans = 1;
    for (int i = 0; i <= n; ++i) {
        ans = (ans * powMod(i, factors[i])) % MOD;
    }
    return ans;
}

int solve() {
    int n, k; cin >> n >> k;
    vector<int> f(n);
    for (int i = 0; i < n; ++i) cin >> f[i];
    sort(f.begin(), f.end());
    int v = f[n - k], vTotal = n, vWanted = k;
    for (int i = n - k - 1; i > -1; --i) {
        if (f[i] != v) {
            vTotal -= i + 1;
            break;
        }
    }
    for (int i = n - k + 1; i < n; ++i) {
        if (f[i] != v) {
            vTotal -= n - i;
            vWanted -= n - i;
            break;
        }
    }
    return nCr(vTotal, vWanted);
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}