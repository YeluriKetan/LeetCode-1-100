#include <iostream>
#include <vector>

using namespace std;

void solve() {
    vector<string> board(9);
    for (int i = 0; i < 9; ++i) {
        cin >> board[i];
    }
    for (int i = 0; i < 9; ++i) {
        board[i][(i % 3) * 3 + (i / 3)] = (board[i][(i % 3) * 3 + (i / 3)] - '0') % 9 + 1 + '0';
    }
    for (auto currRow: board) {
        cout << currRow << "\n";
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
