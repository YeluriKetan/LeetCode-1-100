#include <iostream>

using namespace std;

long long solve() {
    int n, k;
    cin >> n >> k;
    long long currPow = 1, ans = 0;
    while (k > 0) {
        if (k & 1) {
            ans = (ans + currPow) % 1000000007;
        }
        k >>= 1;
        currPow = (currPow * n) % 1000000007;
    }
    return ans;
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
