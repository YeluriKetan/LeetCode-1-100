#include <iostream>
#include <algorithm>

using namespace std;

string solve() {
    int s;
    cin >> s;
    string ans;
    for (int i = 9; i > 0; --i) {
        if (s >= i) {
            s -= i;
            ans += to_string(i);
        }
    }
    reverse(ans.begin(), ans.end());
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
