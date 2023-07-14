#include "bits/stdc++.h"
using namespace std;
typedef vector<bool> VB;
typedef pair<int, int> II;

void solve() {
    string s; cin >> s;
    int n = s.size(), currInd = 26;
    vector<bool> seen(26, false);
    vector<char> line(53, CHAR_MAX);
    line[currInd] = s[0];
    seen[s[0] - 'a'] = true;
    for (int i = 1; i < n; ++i) {
        auto currChar = s[i];
        if (line[currInd - 1] == currChar) {
            currInd--;
        } else if (line[currInd + 1] == currChar) {
            currInd++;
        } else if (seen[currChar - 'a']) {
            cout << "NO\n";
            return;
        } else if (line[currInd - 1] == CHAR_MAX) {
            line[currInd - 1] = currChar;
            seen[currChar - 'a'] = true;
            currInd--;
        } else if (line[currInd + 1] == CHAR_MAX) {
            line[currInd + 1] = currChar;
            seen[currChar - 'a'] = true;
            currInd++;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (auto currChar: line) {
        if (currChar != CHAR_MAX) cout << currChar;
    }
    for (int i = 0; i < 26; ++i) {
        if (!seen[i]) cout << string(1, i + 'a');
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}