#include "bits/stdc++.h"
using namespace std;
typedef vector<int> VI;

VI kmp(string s) {
    int n = s.size(), len = 0;
    VI pi(n, 0);
    for (int i = 1; i < n; i++) {
        if (s[i] == s[len]) {
            len++;
            pi[i] = len;
        } else {
            if (len == 0) {
                pi[i] = 0;
            } else {
                len = pi[len - 1];
                i--;
            }
        }
    }
    return pi;
}

string solve() {
    string s; cin >> s;
    VI pi = kmp(s);
    if (pi.back() == 0) {
        return "Just a legend";
    }
    for (int i = 1; i < s.size() - 1; i++) {
        if (pi[i] == pi.back()) {
            return s.substr(0, pi.back());
        }
    }
    if (pi[pi.back() - 1] > 0) {
        return s.substr(0, pi[pi.back() - 1]);
    }
    return "Just a legend";
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
5 2 6 1 3 4
5 4 = 9
2 3 = 5
6 1 = 7