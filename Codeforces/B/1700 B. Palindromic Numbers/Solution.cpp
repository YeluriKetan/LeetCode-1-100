#include <iostream>
#include <algorithm>

using namespace std;

string solve() {
    int n;
    string s, ans;
    cin >> n >> s;
    if (s[0] > '3') {
        int next = 1;
        for (int i = n - 1; i > -1; --i) {
            if (next) {
                if (s[i] - '0' > 1) {
                    ans += (char) ('0' + 11 - (s[i] - '0'));
                    next = 0;
                } else {
                    ans += (char) ('0' + 1 - (s[i] - '0'));
                }
            } else {
                if (s[i] == '0') {
                    ans += '0';
                    next = 1;
                } else {
                    ans += (char) ('0' + 10 - (s[i] - '0'));
                }
            }
        }
    } else {
        for (int i = n - 1; i > -1; --i) {
            ans += (char) ('0' + 9 - (s[i] - '0'));
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
