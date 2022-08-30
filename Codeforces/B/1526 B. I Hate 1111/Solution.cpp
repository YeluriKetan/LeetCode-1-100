#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n, a = 0; cin >> n;
    for (int i = 0; i < 100; ++i) {
        if ((i * 11) % 100 == n % 100) {
            a = i;
            break;
        }
    }
    n -= a * 11;
    if (n < 0) {
        return "NO";
    }
    n /= 100;
    a += (n / 11) * 10;
    n %= 11;
    if (a >= n) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}
