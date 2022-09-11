#include <bits/stdc++.h>

using namespace std;

long long solve() {
    int n, k, ai, temp; cin >> n >> k;
    long long ans = 0;
    map<int, int> modCount;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        temp = (k - ai % k) % k;
        if (temp == 0) {
            continue;
        }
        modCount[temp]++;
        ans = max(ans, (long long) (modCount[temp] - 1) * k + temp);
    }
    return ans > 0 ? ans + 1 : ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}
