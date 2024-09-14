#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    int n; cin >> n;
    ll sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3) return 0;

    vector<bool> sumIsThird(n, false);
    ll rqSum = sum / 3, preSum = 0, preSumCount = 0;
    for (int i = 0; i < n - 2; ++i) {
        preSum += a[i];
        if (preSum == rqSum) {
            sumIsThird[i] = true;
            preSumCount++;
        }
    }
    ll postSum = 0, ans = 0;
    for (int i = n - 1; i >= 2; --i) {
        postSum += a[i];
        if (postSum == rqSum) {
            ans += preSumCount;
        }
        preSumCount -= sumIsThird[i - 2];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}