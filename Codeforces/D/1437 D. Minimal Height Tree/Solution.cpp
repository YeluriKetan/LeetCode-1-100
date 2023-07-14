#include "bits/stdc++.h"
using namespace std;

int solve() {
    int n, ai, prev = 0, currSeqCount = 0; cin >> n;
    vector<int> incSeq;
    cin >> prev;
    for (int i = 2; i <= n; ++i) {
        cin >> ai;
        if (ai > prev) {
            currSeqCount++;
        } else {
            incSeq.push_back(currSeqCount);
            currSeqCount = 1;
        }
        prev = ai;
    }
    incSeq.push_back(currSeqCount);
    int prevLevel = 1, currLevel = 0, levelCount = 1;
    for (auto currSeq: incSeq) {
        if (prevLevel == 0) {
            prevLevel = currLevel;
            currLevel = 0;
            levelCount++;
        }
        currLevel += currSeq;
        prevLevel--;
    }
    return levelCount;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}