#include <iostream>

using namespace std;

string solve(int n) {
    int prev;
    int curr;
    cin >> curr;
    int one = 0, two = 0, more = 0;
    for (int i = 1; i < n; ++i) {
        prev = curr;
        cin >> curr;
        if (more > 0 || two > 1 || one > 2) {
            continue;
        }
        if (curr - prev > 3) {
            more++;
        } else if (curr - prev == 3) {
            two++;
        } else if (curr - prev == 2) {
            one++;
        }
    }
    if (more == 0 && ((one <= 2 && two == 0) || (one == 0 && two == 1))) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
