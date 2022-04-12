#include <iostream>

using namespace std;

void solve(int n) {
    cout << n - 3 << " 1 1 1\n";
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
