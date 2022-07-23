#include <iostream>

using namespace std;

int solve(int n) {
    int ans = 0, curr;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        ans |= curr;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
