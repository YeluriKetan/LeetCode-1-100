#include <iostream>

using namespace std;

int solve() {
    int n, pi, ans = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> pi;
        if (pi != i) {
            ans &= pi;
        }
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
