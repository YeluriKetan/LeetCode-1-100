#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, ai, count = 0, q, xi, ki, currVal;
    cin >> n;
    vector<map<int, int>> counterMaps;
    vector<int> initVec(n);
    map<int, int> currCounter;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        currCounter[ai]++;
        initVec[i] = ai;
    }
    counterMaps.push_back(currCounter);
    bool changed = true;
    while (changed) {
        changed = false;
        map<int, int> newCounter;
        for (auto curr: counterMaps.back()) {
            if (curr.first != curr.second) {
                changed = true;
            }
            newCounter[curr.second] += curr.second;
        }
        if (changed) {
            counterMaps.push_back(newCounter);
            count++;
        }
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> xi >> ki;
        currVal = initVec[xi - 1];
        ki = min(ki, (int) counterMaps.size());
        for (int j = 0; j < ki; ++j) {
            currVal = counterMaps[j][currVal];
        }
        cout << currVal << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}