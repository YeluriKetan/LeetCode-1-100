#include <iostream>
#include <vector>

using namespace std;

bool ensure(vector<vector<char>> &matrix, int x, int y, int n, int m) {
    int count = 0;
    for (int j = y; j < m; ++j) {
        if (matrix[x][j] == 1) {
            count++;
            matrix[x][j] = 2;
        } else if (matrix[x][j] == 2) {
            return false;
        } else {
            break;
        }
    }
    int temp;
    for (int i = x + 1; i < n; ++i) {
        temp = 0;
        for (int j = y; j < y + count; ++j) {
            if (matrix[i][j] == 1) {
                temp++;
                matrix[i][j] = 2;
            } else if (matrix[i][j] == 2) {
                return false;
            } else {
                temp--;
            }
        }
        if (temp == -count) {
            break;
        } else if ((temp != count) || (y + count < m && matrix[i][y + count] != 0)) {
            return false;
        }
    }
    return true;
}

string solve(int n, int m) {
    string s;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                if (!ensure(matrix, i, j, n, m)) {
                    return "NO";
                }
            }
        }
    }
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> m;
        cout << solve(n, m) << "\n";
    }
    return 0;
}
