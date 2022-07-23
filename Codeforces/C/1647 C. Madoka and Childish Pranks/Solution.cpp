#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m, count = 0;
    cin >> n >> m;
    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
        for (auto currChar: strings[i]) {
            if (currChar == '1') {
                count++;
            }
        }
    }
    if (strings[0][0] == '1') {
        cout << "-1\n";
        return;
    }
    cout << count << "\n";
    for (int i = n - 1; i > -1; --i) {
        for (int j = m - 1; j > 0; --j) {
            if (strings[i][j] == '1') {
                cout << i + 1 << " " << j << " " << i + 1 << " " << j + 1 << "\n";
            }
        }
        if (strings[i][0] == '1') {
            cout << i << " " << 1 << " " << i + 1 << " " << 1 << "\n";
        }
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
