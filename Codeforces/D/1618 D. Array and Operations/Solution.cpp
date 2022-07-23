#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
    int n, k, total = 0;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n - 2 * k; ++i) {
        total += vec[i];
    }
    for (int i = n - 2 * k; i < n - k; ++i) {
        total += vec[i] / vec[i + k];
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solve() << "\n";
    }
    return 0;
}
