#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007;

int main() {
    ios::sync_with_stdio(false);
    vector<int> after(200010), curr(10, 0);
    after[0] = curr[0] = 1;
    int temp, start = 0;
    for (int i = 1; i < 200010; ++i) {
        temp = (start + 9) % 10;
        curr[start] = (curr[start] + curr[temp]) % MOD;
        after[i] = (after[i - 1] + curr[temp]) % MOD;
        start = temp;
    }
    int t, n, m, ans; cin >> t;
    while (t--) {
        cin >> n >> m;
        ans = 0;
        while (n) {
            ans = (ans + after[m + n % 10]) % MOD;
            n /= 10;
        }
        cout << ans << "\n";
    }
    return 0;
}