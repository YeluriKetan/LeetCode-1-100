#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, temp;
    cin >> n;
    vector<int> f(n + 1);
    vector<int> abc(3, 0);
    for (int i = 0; i <= n; ++i) {
        cin >> f[i];
    }
    for (int i = 65536; i > 0; i /= 2) {
        if (i > n) {
            continue;
        }
        temp = (3 - ((f[i] - f[0]) / i)) / 2;
        for (int j = 0; j < temp; ++j) {
            abc[j] += i;
        }
        sort(abc.begin(), abc.end());
    }
    cout << abc[0] << " " << abc[1] << " " << abc[2] << "\n";
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