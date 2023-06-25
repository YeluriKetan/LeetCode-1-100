#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> LL;
typedef vector<int> VI;

LL dfsDP(int ind, int parent, vector<LL> &ranges, vector<VI> &tree) {
    LL currBeauty = {0, 0};
    for (auto child: tree[ind]) {
        if (child != parent) {
            auto childResult = dfsDP(child, ind, ranges, tree);
            currBeauty.first += max(childResult.first + abs(ranges[ind].first - ranges[child].first),
                                    childResult.second + abs(ranges[ind].first - ranges[child].second));
            currBeauty.second += max(childResult.first + abs(ranges[ind].second - ranges[child].first),
                                    childResult.second + abs(ranges[ind].second - ranges[child].second));
        }
    }
    return currBeauty;
}

ll solve() {
    ll n, li, ri; cin >> n;
    int u, v;
    vector<LL> ranges(n + 1);
    vector<VI> tree(n + 1, VI());
    for (int i = 1; i <= n; ++i) {
        cin >> li >> ri;
        ranges[i] = {li, ri};
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    auto result = dfsDP(1, 0, ranges, tree);
    return max(result.first, result.second);
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}