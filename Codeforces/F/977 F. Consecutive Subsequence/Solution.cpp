#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;

void solve() {
    int n, ai, maxCount = 0, maxCountInd; cin >> n;
    vector<ii> prevAndCount(n, {-1, 0});
    map<int, int> lastSeen;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        auto it = lastSeen.find(ai - 1);
        if (it == lastSeen.end()) {
            prevAndCount[i] = {-1, 1};
        } else {
            prevAndCount[i] = {it->second, prevAndCount[it->second].second + 1};
        }
        lastSeen[ai] = i;
        if (prevAndCount[i].second > maxCount) {
            maxCount = prevAndCount[i].second;
            maxCountInd = i;
        }
    }
    cout << maxCount << endl;
    vector<int> ans;
    for (int i = maxCountInd; i != -1; i = prevAndCount[i].first) {
        ans.push_back(i + 1);
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}