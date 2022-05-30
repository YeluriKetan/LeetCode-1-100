#include <iostream>

using namespace std;

string solve() {
    int n, prev = 0, ai;
    cin >> n;
    bool ans = false;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        if (prev >= ai) {
            ans = true;
        }
        prev = ai;
    }
    if (n % 2 == 0) {
        ans = true;
    }
    return ans ? "YES" : "NO";
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
