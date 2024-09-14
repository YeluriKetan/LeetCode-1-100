#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<ll> arr(n), sums;
    ll currSum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        currSum += arr[i];
        if (i >= m) currSum -= arr[i - m];
        if (i >= m - 1) sums.push_back(currSum);
    }
    int l = 0, len = n - k * m + 1;
    vector<ll> dp(len, 0);
    for (int i = 0; i < k; ++i) {
        ll runningMax = 0;
        for (int j = 0; j < len; ++j) {
            runningMax = max(runningMax, dp[j]);
            dp[j] = runningMax + sums[l + j];
        }
        l += m;
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}