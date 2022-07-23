#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
    int n, k;
    string s;
    char c;
    vector<bool> special(26, false);
    cin >> n >> s >> k;
    for (int i = 0; i < k; ++i) {
        cin >> c;
        special[c - 'a'] = true;
    }
    int count = 0, maxVal = 0;
    for (int i = 0; i < n; ++i) {
        if (special[s[i] - 'a']) {
            maxVal = max(maxVal, count);
            count = 1;
        } else {
            count++;
        }
    }
    return maxVal;
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