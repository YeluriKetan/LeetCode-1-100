#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define MOD 1000000007;

int solve() {
    int n, m; cin >> n >> m;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 2; j <= n; ++j) {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ans = (ans + (ll) dp[i] * (ll) dp[n - j + 1]) % MOD;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}