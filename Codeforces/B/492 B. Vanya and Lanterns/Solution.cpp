#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, l; cin >> n >> l;
    vector<int> lamps(n);
    for (int i = 0; i < n; ++i) {
        cin >> lamps[i];
    }
    sort(lamps.begin(), lamps.end());
    double d = 0;
    for (int i = 1; i < n; ++i) {
        d = max(d, (double) (lamps[i] - lamps[i - 1]) / 2);
    }
    d = max(d, (double) lamps[0]);
    d = max(d, (double) l - lamps[n - 1]);
    printf("%.10f\n", d);
    return 0;
}
