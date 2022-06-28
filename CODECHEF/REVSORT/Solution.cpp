#include <iostream>
#include <algorithm>

using namespace std;

string solve() {
    int n;
    long long x, ai, maxPrev = 0, maxSum = 0;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        if (maxPrev > ai) {
            maxSum = max(maxSum, ai + maxPrev);
        }
        maxPrev = max(maxPrev, ai);
    }
    return maxSum > x ? "NO" : "YES";
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
