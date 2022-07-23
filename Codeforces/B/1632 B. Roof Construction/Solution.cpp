#include <iostream>

using namespace std;

void solve(int n) {
    int pow = 131072;
    while (pow >= n) {
        pow /= 2;
    }
    for (int i = pow - 1; i > -1; --i) {
        cout << i << " ";
    }
    for (int i = pow; i < n; ++i) {
        cout << i << " ";
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
