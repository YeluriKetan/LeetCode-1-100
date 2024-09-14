#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;

vector<ii> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

string solve() {
    int n, m, gCount = 0; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'G') {
                gCount++;
            } else if (a[i][j] == 'B') {
                for (auto& dir : dirs) {
                    int x = i + dir.first, y = j + dir.second;
                    if (!valid(x, y, n, m)) {
                        continue;
                    }
                    if (a[x][y] == 'G') {
                        return "No";
                    }
                    if (a[x][y] == '.') {
                        a[x][y] = '#';
                    }
                }
            }
        }
    }
    queue<ii> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    if (a[n - 1][m - 1] != '#') {
        q.push({n - 1, m - 1});
        visited[n - 1][m - 1] = true;
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (a[x][y] == 'G') {
            gCount--;
        }
        for (auto& dir : dirs) {
            int nx = x + dir.first, ny = y + dir.second;
            if (!valid(nx, ny, n, m) || visited[nx][ny] || a[nx][ny] == '#') {
                continue;
            }
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return gCount == 0 ? "Yes" : "No";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}