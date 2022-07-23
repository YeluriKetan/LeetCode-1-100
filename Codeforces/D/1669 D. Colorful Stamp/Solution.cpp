#include <iostream>

using namespace std;

string solve(int n) {
    string s;
    cin >> s;
    int red = 0, blue = 0, len = 0;
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        switch (s[i]) {
            case 'W':
                if (len != 0) {
                    if (len == 1 || red == 0 || blue == 0) {
                        ans = false;
                        i = n + 1;
                    }
                    len = 0;
                    red = 0;
                    blue = 0;
                }
                break;
            case 'R':
                red++;
                len++;
                break;
            case 'B':
                blue++;
                len++;
                break;
            default:
                break;
        }
    }
    if (len != 0) {
        if (len == 1 || red == 0 || blue == 0) {
            ans = false;
        }
    }
    return ans ? "YES" : "NO";
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
