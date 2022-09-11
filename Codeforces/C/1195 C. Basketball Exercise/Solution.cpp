#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<long long> a(n + 1), b(n + 1);
    a[n] = b[n] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = n - 2; i > -1; --i) {
        a[i] += max(b[i + 1], b[i + 2]);
        b[i] += max(a[i + 1], a[i + 2]);
    }
    cout << max(a[0], b[0]) << "\n";
    return 0;
}