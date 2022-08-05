#include <iostream>
#include <cmath>

using namespace std;

int factorize(int n, int from) {
    for (int i = from; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1;
}

void solve() {
    int n, a, temp;
    cin >> n;
    temp = factorize(n, 2);
    if (temp == -1) {
        cout << "NO\n";
        return;
    } else {
        a = temp;
        n /= a;
    }
    temp = factorize(n, a + 1);
    if (temp == -1 || n / temp == a || n / temp == temp) {
        cout << "NO\n";
        return;
    } else {
        n /= temp;
        cout << "YES\n" << a << " " << temp << " " << n << "\n";
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
