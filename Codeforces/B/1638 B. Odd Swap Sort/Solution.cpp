#include <iostream>

using namespace std;

string solve(int n) {
    int curr, prevOdd = 0, prevEven = 0;
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (!ans) {
            continue;
        }
        if (curr % 2) {
            if (curr >= prevOdd) {
                prevOdd = curr;
            } else {
                ans = false;
            }
        } else {
            if (curr >= prevEven) {
                prevEven = curr;
            } else {
                ans = false;
            }
        }
    }
    return ans ? "YES" : "NO";
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
