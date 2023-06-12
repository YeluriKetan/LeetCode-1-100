#include "bits/stdc++.h"
using namespace std;

int solve() {
    int n, k, ai, bi, ti, sum = 0; cin >> n >> k;
    vector<int> a, b, both;
    for (int i = 0; i < n; ++i) {
        cin >> ti >> ai >> bi;
        if (ai == 0) {
            if (bi) {
                b.push_back(ti);
                sum += ti;
            }
        } else {
            if (bi) {
                both.push_back(ti);
            }
            else {
                a.push_back(ti);
                sum += ti;
            }
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(both.begin(), both.end(), greater<>());
    int ka = a.size(), kb = b.size(), ap = a.size() - 1, bp = b.size() - 1, bothp = both.size() - 1;
    while (ka < k && bothp > -1) {
        sum += both[bothp];
        ka++; kb++; bothp--;
    }
    while (kb < k && bothp > -1) {
        sum += both[bothp];
        ka++; kb++; bothp--;
    }
    while (ka > k && ap > -1) {
        sum -= a[ap];
        ka--; ap--;
    }
    while (kb > k && bp > -1) {
        sum -= b[bp];
        kb--; bp--;
    }
    if (ka < k || kb < k) return -1;
    while (bothp > -1 && ap > -1 && bp > -1) {
        if (both[bothp] < a[ap] + b[bp]) {
            sum += both[bothp--] - a[ap--] - b[bp--];
        } else {
            break;
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}