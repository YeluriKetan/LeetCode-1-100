#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve() {
    int n;
    cin >> n;
    vector<long long> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    long long currTotal, prev, totalMin = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        currTotal = 0, prev = 0;
        for (int j = i - 1; j > -1; --j) {
            currTotal += prev / vec[j] + 1;
            prev = vec[j] * (prev / vec[j] + 1);
        }
        prev = 0;
        for (int j = i + 1; j < n; ++j) {
            currTotal += prev / vec[j] + 1;
            prev = vec[j] * (prev / vec[j] + 1);
        }
        totalMin = min(totalMin, currTotal);
    }
    return totalMin;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
