#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

bool isLower(string &a, string &b) {
    int aL = 0, aN = a.size(), bL = 0, bN = b.size();
    while (aL < aN && bL < bN) {
        if (a[aL] < b[bL]) {
            return true;
        } else if (a[aL] > b[bL]) {
            return false;
        }
        aL++;
        bL++;
    }
    return aN <= bN;
}

ll solve() {
    ll n, prevSum = 0, prevSumRev = 0, currSum = 0, currSumRev = 0; cin >> n;
    vector<ll> c(n);
    string prev = "", prevRev = "", s, sRev;
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) {
        currSum = currSumRev = LONG_LONG_MAX;
        cin >> s;
        if (isLower(prev, s)) currSum = min(currSum, prevSum);
        if (isLower(prevRev, s)) currSum = min(currSum, prevSumRev);

        sRev = s;
        reverse(sRev.begin(), sRev.end());
        if (isLower(prev, sRev)) currSumRev = min(currSumRev, prevSum);
        if (isLower(prevRev, sRev)) currSumRev = min(currSumRev, prevSumRev);
        currSumRev += c[i];
        currSumRev = currSumRev < 0 ? LONG_LONG_MAX : currSumRev;

        if (currSum == LONG_LONG_MAX && currSumRev == LONG_LONG_MAX) return -1;
        prev = s; prevRev = sRev;
        prevSum = currSum, prevSumRev = currSumRev;
    }
    return min(prevSum, prevSumRev);
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}