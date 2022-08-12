#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2) {
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                cout << n / i << " " << n - (n / i) << "\n";
                return;
            }
        }
        cout << "1 " << n - 1 << "\n";
    } else {
        cout << n / 2 << " " << n / 2 << "\n";
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
