#include <iostream>

using namespace std;

string solve(int n, int k, string s) {
    int d = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            d++;
        }
    }
    if (k < d) {
        return "NO";
    }
    k -= d;
    if (k % 2 == 0) {
        return "YES";
    } else {
        return n % 2 == 1 ? "YES" : "NO";
    }
}

int main() {
    int t, n, k;
    cin >> t;
    string s;
    for (int i = 0; i < t; ++i) {
        cin >> n >> k >> s;
        cout << solve(n, k, s) << "\n";
    }
    return 0;
}
