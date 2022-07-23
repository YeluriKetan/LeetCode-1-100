#include <iostream>
#include <algorithm>

using namespace std;

int solve(int l, int r, int a) {
    int ans = r / a + r % a;
    r -= r % a + 1;
    if (r >= l) {
        return max(ans, r / a + a - 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, l, r, a;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> l >> r >> a;
        cout << solve(l, r, a) << "\n";
    }
    return 0;
}
