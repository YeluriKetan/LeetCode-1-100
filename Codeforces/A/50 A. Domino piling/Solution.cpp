#include <iostream>

using namespace std;

int solve() {
    int m, n;
    cin >> m >> n;
    if (m % 2 == 0) {
        return m / 2 * n;
    } else if (n % 2 == 0) {
        return n / 2 * m;
    } else {
        return ((m - 1) / 2) * n + (n - 1) / 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << solve() << "\n";
}
