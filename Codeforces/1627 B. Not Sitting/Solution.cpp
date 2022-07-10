#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, minDist, maxDist, currMax;
    cin >> n >> m;
    minDist = n / 2 + m / 2;
    maxDist = n + m - 2;
    vector<int> count(maxDist - minDist + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            currMax = abs(1 - i) + abs(1 - j);
            currMax = max(currMax, abs(1 - i) + abs(m - j));
            currMax = max(currMax, abs(n - i) + abs(1 - j));
            currMax = max(currMax, abs(n - i) + abs(m - j));
            count[currMax - minDist]++;
        }
    }
    for (int i = 0; i < count.size(); ++i) {
        for (int j = 0; j < count[i]; ++j) {
            cout << i + minDist << " ";
        }
    }
    cout << "\n";
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