#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> II;

int solve() {
    int n; cin >> n;
    vector<int> a(n + 2);
    vector<II> subSeg;
    a[0] = 1e9 + 1;
    int prevStart = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i - 1] >= a[i]) {
            subSeg.emplace_back(prevStart, i - prevStart);
            prevStart = i;
        }
    }
    subSeg[0].second = a[n + 1] = 0;
    subSeg.emplace_back(prevStart, n - prevStart + 1);
    subSeg.emplace_back(n + 1, 0);
    int maxLen = 1, maxSubSegLen = 1, sN = subSeg.size();
    for (int i = 1; i < sN - 1; ++i) {
        auto [start, len] = subSeg[i];
        if (len == 1) {
            if (a[start - 1] + 1 < a[start + 1]) {
                maxLen = max(maxLen, subSeg[i - 1].second + subSeg[i + 1].second + 1);
            } else {
                maxLen = max(maxLen,
                             max(subSeg[i - 1].second, subSeg[i + 1].second) + 1);
            }
        } else {
            if (a[start - 1] + 1 < a[start + 1]) {
                maxLen = max(maxLen, subSeg[i - 1].second + len);
            }
            if (a[start + len - 2] + 1 < a[start + len]) {
                maxLen = max(maxLen, len + subSeg[i + 1].second);
            }
            maxSubSegLen = max(maxSubSegLen, len);
        }
    }
    maxLen = max(maxLen, min(n, maxSubSegLen + 1));
    return maxLen;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}