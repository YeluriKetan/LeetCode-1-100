#include "bits/stdc++.h"
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<set<int>> indices(26, set<int>());
    for (int i = 0; i < n; ++i) indices[s[i] - 'a'].insert(i + 1);
    int q, qi, ai, bi; cin >> q;
    char c, prevC;
    while (q--) {
        cin >> qi;
        if (qi == 1) {
            cin >> ai >> c;
            prevC = s[ai - 1];
            s[ai - 1] = c;
            indices[prevC - 'a'].erase(ai);
            indices[c - 'a'].insert(ai);
        } else {
            cin >> ai >> bi;
            int u = 0;
            for (auto &currSet: indices) {
                auto it = currSet.lower_bound(ai);
                if (it != currSet.end() && *it <= bi) u++;
            }
            cout << u << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}