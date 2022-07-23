#include <iostream>

using namespace std;

string solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (m < n - 1 || m > (((long long) n) * (n - 1)) / 2) {
        return "NO";
    }
    if (k < 2) {
        return "NO";
    } else if (k == 2) {
        return n == 1 ? "YES" : "NO";
    } else if (k == 3) {
        return (m == ((((long long) n) * (n - 1)) / 2)) ? "YES" : "NO";
    } else {
        return "YES";
    }
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
