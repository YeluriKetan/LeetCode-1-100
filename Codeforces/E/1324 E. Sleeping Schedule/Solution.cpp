#include "bits/stdc++.h"
using namespace std;

int addCheckGood(int t, int l, int r) {
    return (l <= t && t <= r) ? 1 : 0;
}

int solve() {
    int n, h, l, r, ai, baseTime = 0; cin >> n >> h >> l >> r;
    vector<int> times = {0};
    for (int i = 0; i < n; i++) {
        cin >> ai;
        baseTime += ai - 1;
        vector<int> newTimes;
        newTimes.push_back(times[0] + addCheckGood(baseTime % h, l, r));
        for (int j = 1; j < times.size(); ++j) {
            newTimes.push_back(max(times[j], times[j - 1]) + addCheckGood((baseTime + j) % h, l, r));
        }
        newTimes.push_back(times[i] + addCheckGood((baseTime + i + 1) % h, l, r));
        times = newTimes;
        baseTime %= h;
    }
    return *max_element(times.begin(), times.end());
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}