#include "bits/stdc++.h"
using namespace std;

string solve() {
    int n, k; cin >> n >> k;
    char c;
    vector<int> charCount(27, 0);
    for (int i = 0; i < n; ++i) {
        cin >> c;
        charCount[c - 96]++;
    }
    int count = 0, n1, c1 = 0, ck = 0, nK1 = 0, ck1 = 0, cn = 0;
    for (int i = 1; i < 27; ++i) {
        count += charCount[i];
        if (count >= 1 && !c1) {
            c1 = i;
            n1 = min(count, k);
        }
        if (count >= k && !ck) { ck = i; }
        if (count >= k + 1 && !ck1) {
            ck1 = i;
            nK1 = count - k;
        }
        if (count >= n && ck1 && !cn) { cn = i; }
    }
    if (ck == c1) {
        if (ck1 == cn) {
            return string(1, c1 + 96) + string(ceil(nK1 / (double) n1), ck1 + 96);
        } else {
            auto ans = string(1, c1 + 96) + string(nK1, ck1 + 96);
            for (int i = ck1 + 1; i < 27; ++i) {
                ans += string(charCount[i], i + 96);
            }
            return ans;
        }
    } else {
        return string(1, ck + 96);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
