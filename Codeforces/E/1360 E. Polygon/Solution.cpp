#include <iostream>
#include <vector>

using namespace std;

void dfs(int x, int y, vector<string> &grid) {
    if (grid[x][y] == '0') {
        return;
    }
    grid[x][y] = '0';
    if (x > 0) {
        dfs(x - 1, y, grid);
    }
    if (y > 0) {
        dfs(x, y - 1, grid);
    }
}

string solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    for (int i = n - 1; i > -1; --i) {
        dfs(n - 1, i, grid);
    }
    for (int i = n - 2; i > -1; --i) {
        dfs(i, n - 1, grid);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                return "NO";
            }
        }
    }
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solve() << "\n";
    }
    return 0;
}
