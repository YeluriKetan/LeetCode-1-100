#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n, aliceMax = -1, m, bobMax = -1, temp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        aliceMax = max(aliceMax, temp);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        bobMax = max(bobMax, temp);
    }
    if (aliceMax >= bobMax) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
    if (bobMax >= aliceMax) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
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
