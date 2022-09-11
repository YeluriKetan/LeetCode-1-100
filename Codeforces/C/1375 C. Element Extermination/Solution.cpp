#include "bits/stdc++.h"
using namespace std;

string solve() {
    int n, a1, an; cin >> n >> a1;
    n--;
    while (n--) {
        cin >> an;
    }
    return a1 > an ? "NO" : "YES";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}