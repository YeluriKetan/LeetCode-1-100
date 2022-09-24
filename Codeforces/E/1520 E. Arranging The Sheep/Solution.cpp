#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    int n, c = 0, m; cin >> n;
    string s; cin >> s;
    vector<int> v;
    ll sum = 0, o = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '*') {
            v.push_back(i);
            c++;
        }
    }
    c = (c + 1) / 2 - 1;
    for (int i = 0; i < v.size(); ++i) {
        if (i < c) {
            sum += v[i] + o++;
        } else if (i == c) {
            sum = (ll) v[i] * i - sum;
            m = v[i];
            o = 1;
        } else {
            sum += v[i] - o++ - m;
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}