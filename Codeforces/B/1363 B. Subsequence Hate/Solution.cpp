#include <bits/stdc++.h>
using namespace std;

int solve() {
    string s; cin >> s;
    int leftCount = 0, rightCount = 0, n = s.size();
    for (auto currChar: s) {
        if (currChar == '1') {
            rightCount++;
        }
    }
    int minOper = n;
    for (int i = 0; i < n; ++i) {
        minOper = min(minOper, leftCount + n - i - rightCount);
        minOper = min(minOper, i - leftCount + rightCount);
        if (s[i] == '1') {
            leftCount++;
            rightCount--;
        }
    }
    return minOper;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}
