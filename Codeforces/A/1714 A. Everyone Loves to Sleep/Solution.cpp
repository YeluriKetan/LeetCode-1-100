#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n, H, M, T, hi, mi, ti, minTi = INT_MAX, minGreaterTi = INT_MAX;
    cin >> n >> H >> M;
    T = H * 60 + M;
    for (int i = 0; i < n; ++i) {
        cin >> hi >> mi;
        ti = hi * 60 + mi;
        minTi = min(minTi, ti);
        if (ti >= T) {
            minGreaterTi = min(minGreaterTi, ti);
        }
    }
    if (minGreaterTi != INT_MAX) {
        T = minGreaterTi - T;
    } else {
        if (minTi < T) {
            T = 24 * 60 - T + minTi;
        } else {
            T = minTi - T;
        }
    }
    cout << T / 60 << " " << T % 60 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
