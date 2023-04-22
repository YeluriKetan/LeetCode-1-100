#include "bits/stdc++.h"
using namespace std;

int main() {
    long long n, k, m, i; cin >> n >> k;
    m = sqrt(n);
    for (i = 1; i <= m && k; ++i) {
        if (n % i == 0) k--;
    }
    if (k == 0) { cout << i - 1 << endl; return 0; }
    for (i = (m * m == n ? m - 1 : i - 1); i > 0 && k; i--) {
        if (n % i == 0) k--;
    }
    cout << (k ? -1 : n / (i + 1)) << endl;
    return 0;
}
