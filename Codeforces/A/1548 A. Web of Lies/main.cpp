#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n, m, u, v, q, qi, cVul = 0; cin >> n >> m;
    unordered_map<int, unordered_set<int>> f;
    vector<bool> vul(n + 1, false);
    while (m--) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        auto it = f.emplace(u, unordered_set<int>());
        it.first.operator*().second.insert(v);
        if (!vul[u]) cVul++;
        vul[u] = true;
    }
    cin >> q;
    while (q--) {
        cin >> qi;
        if (qi == 3) {
            cout << n - cVul << "\n";
        } else {
            cin >> u >> v;
            if (u > v) swap(u, v);
            if (qi == 1) {
                auto it = f.emplace(u, unordered_set<int>());
                it.first.operator*().second.insert(v);
                if (!vul[u]) cVul++;
                vul[u] = true;
            } else {
                f[u].erase(v);
                if (f[u].empty()) {
                    cVul--;
                    vul[u] = false;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}