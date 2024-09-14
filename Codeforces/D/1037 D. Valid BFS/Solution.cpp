#include "bits/stdc++.h"
using namespace std;
typedef vector<int> VI;

string solve() {
    int n, u, v, ai; cin >> n;
    unordered_map<int, VI> tree;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        auto it = tree.emplace(u, VI());
        it.first->second.push_back(v);
        it = tree.emplace(v, VI());
        it.first->second.push_back(u);
    }
    queue<int> q;
    q.push(1);
    q.push(-1);
    unordered_set<int> parityCheck;
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        if (q.front() == -1) {
            if (!parityCheck.empty()) {
                return "No";
            }
            q.pop();
        }
        auto x = q.front(); q.pop();
        if (parityCheck.find(x) == parityCheck.end()) {
            parityCheck.insert(x);
        } else {
            parityCheck.erase(x);
        }
        if (parityCheck.find(ai) == parityCheck.end()) {
            parityCheck.insert(ai);
        } else {
            parityCheck.erase(ai);
        }
        bool pushed = false;
        for (auto neighbour: tree[ai]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
                pushed = true;
            }
        }
        if (pushed) {
            q.push(-1);
        }
    }
    return "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
// 1 2
// 1 5
// 2 3
// 2 4
// 5 6