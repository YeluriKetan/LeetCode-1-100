#include "bits/stdc++.h"

using namespace std;

int solve() {
    int n, currMax, ans = 1; cin >> n;
    vector<int> sizes(n + 1), dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> sizes[i];
    }
    for (int i = n; i > 0; --i) {
        currMax = 0;
        for (int j = 2 * i; j <= n; j += i) {
            if (sizes[j] > sizes[i]) {
                currMax = max(currMax, dp[j]);
            }
        }
        dp[i] = currMax + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}