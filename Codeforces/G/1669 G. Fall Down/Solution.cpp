#include <iostream>

using namespace std;

void solve(int n, int m) {
    string s;
    char grid[n][m];
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = s[j];
        }
    }
    int target;
    for (int j = 0; j < m; ++j) {
        target = n - 1;
        for (int i = n - 1; i > -1; --i) {
            switch (grid[i][j]) {
                case '.':
                    break;
                case '*':
                    if (target == i) {
                        target--;
                    } else {
                        grid[target--][j] = '*';
                        grid[i][j] = '.';
                    }
                    break;
                case 'o':
                    target = i - 1;
                    break;
                default:
                    break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
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
