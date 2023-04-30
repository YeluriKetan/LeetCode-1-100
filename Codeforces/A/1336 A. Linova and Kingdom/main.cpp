#include "bits/stdc++.h"
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef tuple<int, int, int> III;

int dfs(VVI &tree, VI &subCount, int curr) {
    int count = 0;
    for (auto child: tree[curr]) {
        tree[child].erase(std::find(tree[child].begin(), tree[child].end(), curr));
        count += dfs(tree, subCount, child) + 1;
    }
    subCount[curr] = count;
    return count;
}

struct bestCity {
    bool operator()(const III &a, const III &b) {
        return get<2>(a) < get<2>(b);
    }
};

long long solve() {
    int n, k, u, v; cin >> n >> k;
    int tour = n - k;
    long long t = 0;
    vector<VI> tree(n + 1, VI());
    VI subCount(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(tree, subCount, 1);
    priority_queue<III, vector<III>, bestCity> pq;
    pq.push({1, 0, subCount[1]});
    while (!pq.empty() && tour) {
        for (int i = pq.size(); i > 0 && tour; --i) {
            auto curr = pq.top(); pq.pop();
            t += get<2>(curr);
            tour--;
            for (auto child: tree[get<0>(curr)]) {
                pq.push({child, get<1>(curr) + 1, subCount[child] - get<1>(curr) - 1});
            }
        }
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}