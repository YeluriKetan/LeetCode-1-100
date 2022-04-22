#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmpWeights(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

bool cmpCords(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

void solve(int n, int m) {
    vector<vector<int>> points(m);
    int cord, weight, totalWeight = 0;
    for (int i = 0; i < m; ++i) {
        cin >> cord >> weight;
        totalWeight += weight;
        vector<int> newVec = {weight, cord, i + 1};
        points[i] = newVec;
    }
    sort(points.begin(), points.end(), cmpWeights);
    for (int i = 2 * n; i < m; ++i) {
        totalWeight -= points[i][0];
    }
    points.erase(points.end() - m + 2 * n, points.end());
    sort(points.begin(), points.end(), cmpCords);
    cout << totalWeight << "\n";
    for (int i = 0; i < n; ++i) {
        cout << points[i][2] << " " << points[2 * n - 1 - i][2] << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> m;
        solve(n, m);
    }
    return 0;
}

