#include <iostream>
#include <vector>

using namespace std;

int solve() {
    int n, k, ai, index, ans = 0;
    cin >> n >> k;
    vector<int> counter(31, 0);
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        index = 0;
        while (ai) {
            counter[index++] += ai & 1;
            ai >>= 1;
        }
    }
    for (int i = 30; i > -1; --i) {
        ans <<= 1;
        if (n - counter[i] <= k) {
            k -= n - counter[i];
            ans++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solve() << "\n";
    }
    return 0;
}
