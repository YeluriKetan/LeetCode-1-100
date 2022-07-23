#include <iostream>

using namespace std;

void solve() {
    int n, k;
    string s, newS, countS;
    bool odd;
    cin >> n >> k >> s;
    odd = k % 2 == 1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '0') {
            if (odd) {
                newS += "1";
                countS += "0 ";
            } else {
                if (k) {
                    newS += "1";
                    countS += "1 ";
                    k--;
                } else {
                    newS += "0";
                    countS += "0 ";
                }
            }
        } else {
            if (odd) {
                if (k) {
                    newS += "1";
                    countS += "1 ";
                    k--;
                } else {
                    newS += "0";
                    countS += "0 ";
                }
            } else {
                newS += "1";
                countS += "0 ";
            }
        }
    }
    countS += to_string(k);
    if (odd) {
        if (k % 2) {
            newS += s[n - 1];
        } else {
            newS += (s[n - 1] - '0' + 1) % 2 + '0';
        }
    } else {
        if (k % 2) {
            newS += (s[n - 1] - '0' + 1) % 2 + '0';
        } else {
            newS += s[n - 1];
        }
    }
    cout << newS << "\n" << countS << "\n";
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
