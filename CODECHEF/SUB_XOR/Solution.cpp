#include <iostream>

using namespace std;

int solve(int n, string s) {
    int mod = 998244353;
    int curr = 0, flag = 0;
    for (int i = 0; i < n; ++i) {
        curr <<= 1;
        if (s[i] == '1') {
            flag ^= (i + 1) % 2;
        }
        curr += flag;
        curr %= mod;
    }
    return curr;
}

int main() {
    int t, n;
    string s;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> s;
        cout << solve(n, s) << "\n";
    }
    return 0;
}
