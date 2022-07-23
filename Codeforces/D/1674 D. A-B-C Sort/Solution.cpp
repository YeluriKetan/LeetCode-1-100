#include <iostream>

using namespace std;

string solve() {
    int n;
    cin >> n;
    int prev = 0, a, b;
    bool ans = true;
    if (n % 2) {
        cin >> prev;
    }
    for (int i = (n % 2) ? 1 : 0; i < n; i += 2) {
        if (!ans) {
            cin >> a >> b;
            continue;
        }
        cin >> a >> b;
        if (a >= b) {
            if (b >= prev) {
                prev = a;
            } else {
                ans = false;
            }
        } else {
            if (a >= prev) {
                prev = b;
            } else {
                ans = false;
            }
        }
    }
    return ans ? "YES" : "NO";
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
