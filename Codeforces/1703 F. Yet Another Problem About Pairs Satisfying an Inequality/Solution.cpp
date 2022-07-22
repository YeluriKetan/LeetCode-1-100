#include <iostream>
#include <vector>

using namespace std;

long long solve() {
    int n, ai;
    long long total = 0;
    cin >> n;
    vector<long long> prevPairs(n + 1);
    prevPairs[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> ai;
        if (ai < i) {
            prevPairs[i] = prevPairs[i - 1] + 1;
            if (ai > 0) {
                total += prevPairs[ai - 1];
            }
        } else {
            prevPairs[i] = prevPairs[i - 1];
        }
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
