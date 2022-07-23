#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
    string s;
    cin >> s;
    int len = s.size();
    vector<int> memo(len + 1, INT_MAX);
    vector<int> lastSeen(26, -1);
    memo[len] = 0;
    for (int i = len - 1; i > -1; --i) {
        if (lastSeen[s[i] - 'a'] != -1) {
            memo[i] = min(memo[i], memo[lastSeen[s[i] - 'a'] + 1] + lastSeen[s[i] - 'a'] - i - 1);
        }
        memo[i] = min(memo[i], memo[i + 1] + 1);
        lastSeen[s[i] - 'a'] = i;
    }
    return memo[0];
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
