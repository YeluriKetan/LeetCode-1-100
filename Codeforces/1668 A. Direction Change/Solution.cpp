#include <iostream>

using namespace std;

int solve() {
    int n, m;
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }
    if (n == 1) {
        if (m < 3) {
            return m - 1;
        } else {
            return -1;
        }
    }
    return m + n - 2 + ((m - n) / 2) * 2;
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
