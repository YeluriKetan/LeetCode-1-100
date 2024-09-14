#include "bits/stdc++.h"
using namespace std;

void solve() {
    int t, k; cin >> t >> k;
    vector<int> dp, preSum;
    dp.push_back(1);
    preSum.push_back(1);
    for (int i = 0; i < t; i++) {
        int a, b; cin >> a >> b;
        for (int j = dp.size(); j <= b; ++j) {
            dp.push_back((dp[j - 1] + (j >= k ? dp[j - k] : 0)) % 1000000007);
            preSum.push_back((preSum[j - 1] + dp[j]) % 1000000007);
        }
        cout << (preSum[b] - preSum[a - 1] + 1000000007) % 1000000007 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
