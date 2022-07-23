#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int grid[200][200];

int solve() {
    int n, m;
    cin >> n >> m;
    vector<int> lrSums(n + m - 1, 0);
    vector<int> rlSums(n + m - 1, 0);
    int temp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> temp;
            lrSums[n - 1 + j - i] += temp;
            rlSums[j + i] += temp;
            grid[i][j] = temp;
        }
    }
    int maxVal = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            temp = 0;
            temp += lrSums[n - 1 + j - i];
            temp += rlSums[j + i];
            temp -= grid[i][j];
            maxVal = max(maxVal, temp);
        }
    }
    return maxVal;
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
