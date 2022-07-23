#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, ci;
    cin >> n;
    vector<vector<int>> color(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        cin >> ci;
        color[ci - 1][i % 2] = color[ci - 1][(i + 1) % 2] + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << max(color[i][0], color[i][1]) << " ";
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
