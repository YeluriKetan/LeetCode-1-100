#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, ai, bi, total = 0, maxTotal = 0; cin >> n;
    while (n--) {
        cin >> ai >> bi;
        total += bi - ai;
        maxTotal = max(maxTotal, total);
    }
    cout << maxTotal << "\n";
    return 0;
}