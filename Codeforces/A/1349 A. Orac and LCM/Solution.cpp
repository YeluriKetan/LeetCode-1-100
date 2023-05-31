#include "bits/stdc++.h"
using namespace std;

int getSecLowest(vector<int> &a, int p) {
    int low = INT_MAX, secLow = INT_MAX, ki;
    for (auto &curr: a) {
        ki = 0;
        while (curr % p == 0) {
            ki++;
            curr /= p;
        }
        if (ki < low) {
            secLow = low;
            low = ki;
        } else if (ki < secLow) {
            secLow = ki;
        }
        if (secLow == 0) {
            return 0;
        }
    }
    return secLow;
}

long long solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long ans = 1;
    ans *= pow(2, getSecLowest(a, 2));
    for (int i = 3; i < 200000; i += 2) {
        ans *= pow(i, getSecLowest(a, i));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}