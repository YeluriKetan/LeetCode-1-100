#include <iostream>

using namespace std;

void solve(int n) {
    if (n > 19) {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    int curr = 1;
    for (int i = 0; i < n; ++i) {
        cout << curr << " ";
        curr *= 3;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        solve(n);
    }
    return 0;
}
