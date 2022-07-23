#include <iostream>

using namespace std;

void solve() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    bool check = false;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] != c) {
            check = true;
            break;
        }
    }
    if (!check) {
        cout << "0\n";
        return;
    }
    for (int i = n / 2 + 1; i <= n; ++i) {
        if (s[i - 1] == c) {
            cout << "1\n" << i << "\n";
            return;
        }
    }
    cout << "2\n" << n << " " << n - 1 << "\n";
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
