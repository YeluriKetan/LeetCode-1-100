#include "bits/stdc++.h"
using namespace std;
typedef vector<char> VC;
typedef vector<bool> VB;

bool dfs(vector<VC> &topo, VB &added, VB &currPath, string &topoOrder, char curr) {
    if (currPath[curr]) {
        return false;
    }
    if (added[curr]) {
        return true;
    }
    currPath[curr] = true;
    for (auto next: topo[curr]) {
        if (!dfs(topo, added, currPath, topoOrder, next)) {
            return false;
        }
    }
    currPath[curr] = false;
    if (!added[curr]) topoOrder += curr + 'a';
    added[curr] = true;
    return true;
}

string solve() {
    int n; cin >> n;
    string p, s; cin >> p;
    n--;
    vector<VC> topo(26, VC());
    while (n--) {
        cin >> s;
        int i, minN = min(p.size(), s.size());
        for (i = 0; i < minN; ++i) {
            if (p[i] != s[i]) {
                topo[p[i] - 'a'].push_back(s[i] - 'a');
                break;
            }
        }
        if (i == minN && p.size() > s.size()) topo[0].push_back(0);
        p = s;
    }
    VB added(26, false), currPath(26, false);
    string topoOrder;
    for (int i = 0; i < 26; ++i) {
        if (!dfs(topo, added, currPath, topoOrder, i)) {
            return "Impossible";
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (!added[i]) topoOrder += i + 'a';
    }
    reverse(topoOrder.begin(), topoOrder.end());
    return topoOrder;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}