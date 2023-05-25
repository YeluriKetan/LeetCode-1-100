#include "bits/stdc++.h"
using namespace std;

void dfs(vector<string> &grid, int x, int y, int &free) {
    if (grid[x][y] != 'X' || free < 1) return;
    grid[x][y] = '.';
    free--;
    if (x > 0) dfs(grid, x - 1, y, free);
    if (x < grid.size() - 1) dfs(grid, x + 1, y, free);
    if (y > 0) dfs(grid, x, y - 1, free);
    if (y < grid[0].size() - 1) dfs(grid, x, y + 1, free);
}

void solve() {
    int n, m, k, w = 0, x, y; cin >> n >> m >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                w++;
            } else {
                grid[i][j] = 'X';
                x = i; y = j;
            }
        }
    }
    int free = n * m - w - k;
    dfs(grid, x, y, free);
    for (auto line: grid) {
        cout << line << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}