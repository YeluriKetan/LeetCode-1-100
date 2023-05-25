#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> II;

class Cmp {
public:
    bool operator()(II &a, II &b) {
        return (a.second == b.second) ? a.first > b.first : a.second < b.second;
    }
};

void solve() {
    int n, i = 1; cin >> n;
    priority_queue<II, vector<II>, Cmp> pq;
    pq.push({0, n});
    vector<int> ans(n, 0);
    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int mid = curr.first + (curr.second - 1) / 2;
        ans[mid] = i++;
        if (curr.first != mid) {
            pq.push({curr.first, mid - curr.first});
        }
        if ((curr.first + curr.second - 1) != mid) {
            pq.push({mid + 1, curr.first + curr.second - 1 - mid});
        }
    }
    for (auto curr: ans) {
        cout << curr << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}