#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
    int n, li, ri;
    cin >> n;
    vector<vector<bool>> grid(n + 1, vector<bool> (n + 1, false));
    for (int i = 0; i < n; ++i) {
        cin >> li >> ri;
        grid[li][ri] = true;
    }
    queue<pair<int, int>> q;
    q.push({1, n});
    pair<int, int> currPair;
    while (!q.empty()) {
        currPair = q.front();
        q.pop();
        cout << currPair.first << " " << currPair.second << " ";
        if (currPair.first == currPair.second) {
            cout << currPair.first;
        } else if (grid[currPair.first][currPair.second - 1]) {
            cout << currPair.second;
            q.push({currPair.first, currPair.second - 1});
        } else if (grid[currPair.first + 1][currPair.second]) {
            cout << currPair.first;
            q.push({currPair.first + 1, currPair.second});
        } else {
            for (int i = currPair.first + 1; i < currPair.second; ++i) {
                if (grid[currPair.first][i - 1] && grid[i + 1][currPair.second]) {
                    cout << i;
                    q.push({currPair.first, i - 1});
                    q.push({i + 1, currPair.second});
                }
            }
        }
        cout << "\n";
    }
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
