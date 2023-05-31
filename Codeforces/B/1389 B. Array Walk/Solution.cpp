#include "bits/stdc++.h"
using namespace std;

int solve() {
    int n, k, z, maxSum = 0; cin >> n >> k >> z;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i <= z; ++i) {
        int currK = k - 2 * i;
        if (currK < 0) continue;
        int currSum = 0, maxPair = 0;
        for (int j = 0; j <= currK; ++j) {
            currSum += a[j];
            if (j < n - 1) maxPair = max(maxPair, a[j] + a[j + 1]);
        }
        currSum += maxPair * i;
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}

