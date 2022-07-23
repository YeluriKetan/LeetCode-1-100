#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solve() {
    int n, m, ai, temp;
    cin >> n >> m;
    string ans(m, 'B');
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        temp = max(ai, m + 1 - ai);
        ai = min(ai, m + 1 - ai);
        if (ans[ai - 1] == 'B') {
            ans[ai - 1] = 'A';
        } else {
            ans[temp - 1] = 'A';
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
