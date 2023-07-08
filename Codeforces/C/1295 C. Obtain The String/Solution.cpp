#include "bits/stdc++.h"
using namespace std;
typedef vector<int> VI;

int solve() {
    string s, t; cin >> s >> t;
    int nS = s.size();
    VI first(26, -1), nextClosest(26, -1);
    vector<VI> next(nS, VI(26, -1));
    for (int i = nS - 1; i > -1; --i) {
        char c = s[i] - 'a';
        first[c] = i;
        for (int j = 0; j < 26; ++j) {
            if (nextClosest[j] != -1) {
                next[i][j] = nextClosest[j];
            }
        }
        nextClosest[c] = i;
    }
    int prevInd = nS - 1, currInd = -1, count = 0;
    for (auto c: t) {
        c -= 'a';
        currInd = next[prevInd][c];
        if (currInd == -1) {
            currInd = first[c];
            count++;
        }
        if (first[c] == -1) {
            count = -1;
            break;
        }
        prevInd = currInd;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}