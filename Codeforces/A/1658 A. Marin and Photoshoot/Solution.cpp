#include <iostream>

using namespace std;

int solve(int n, string s) {
    if (n == 1) {
        return 0;
    }
    int count = s.substr(0, 2) == "00" ? 2 : 0;
    for (int i = 2; i < n; ++i) {
        if (s[i] == '0') {
            if (s[i - 1] == '0') {
                count += 2;
            } else if (s[i - 2] == '0') {
                count += 1;
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    string s;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> s;
        cout << solve(n, s) << "\n";
    }
    return 0;
}
