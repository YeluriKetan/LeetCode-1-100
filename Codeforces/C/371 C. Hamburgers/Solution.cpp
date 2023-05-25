#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    string rec; cin >> rec;
    vector<int> nR(3, 0), nK(3, 0), nP(3, 0);
    ll r, count = 0;
    for (auto ch: rec) {
        if (ch == 'B') nR[0]++;
        else if (ch == 'S') nR[1]++;
        else nR[2]++;
    }
    cin >> nK[0] >> nK[1] >> nK[2] >> nP[0] >> nP[1] >> nP[2] >> r;
    for (int i = 0; i < 3; ++i) {
        if (nR[i] == 0) { nK[i] = 0; }
    }
    while (*max_element(nK.begin(), nK.end()) > 0 && r > 0) {
        for (int i = 0; i < 3; ++i) {
            nK[i] -= nR[i];
            if (nK[i] < 0) {
                r += nK[i] * nP[i];
                nK[i] = 0;
            }
        }
        if (r >= 0) count++;
    }
    if (r > 0) {
        ll t = 0;
        for (int i = 0; i < 3; ++i) t += nR[i] * nP[i];
        count += r / t;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
