#include <iostream>

using namespace std;

void solve(int n, int k) {
    if (k == 1) {
        cout << "YES\n";
        for (int i = 1; i <= n; ++i) {
            cout << i << "\n";
        }
        return;
    }
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << (i * 2 * k) + (2 * j + 1) << " ";
        }
        cout << "\n";
        for (int j = 0; j < k; ++j) {
            cout << (i * 2 * k) + (2 * j + 2) << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n, k;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> k;
        solve(n, k);
    }
    return 0;
}
