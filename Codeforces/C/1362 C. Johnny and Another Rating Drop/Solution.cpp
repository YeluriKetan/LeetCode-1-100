#include "iostream"
using namespace std;

long long solve() {
    long long N, ans = 0, p = 1; cin >> N;
    while (p <= N) {
        ans += N / p;
        p <<= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}