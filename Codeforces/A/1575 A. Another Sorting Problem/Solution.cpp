#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    for (int i = 0; i < a.first.length(); ++i) {
        if (i % 2) {
            if (a.first[i] != b.first[i]) {
                return a.first[i] > b.first[i];
            }
        } else {
            if (a.first[i] != b.first[i]) {
                return a.first[i] < b.first[i];
            }
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    vector<pair<string, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        vec[i] = {s, i + 1};
    }
    sort(vec.begin(), vec.end(), cmp);
    for (auto curr: vec) {
        cout << curr.second << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
