#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll solve() {
    ll n, pBi, a1, b1, ai, bi, T = 0, minLoss = LONG_LONG_MAX, minLossReplace, temp;
    cin >> n >> a1 >> b1;
    n--;
    pBi = b1;
    while (n--) {
        cin >> ai >> bi;
        T += max(0LL, ai - pBi);
        temp = min(ai, pBi);
        if (temp < minLoss) {
            minLoss = temp;
            minLossReplace = ai - max(0LL, ai - pBi);
        }
        pBi = bi;
    }
    T += max(0LL, a1 - pBi);
    if (min(a1, pBi) < minLoss) {
        minLossReplace = a1 - max(0LL, a1 - pBi);
    }
    return T + minLossReplace;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
