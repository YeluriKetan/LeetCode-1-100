#include <iostream>

using namespace std;

int solve(int n) {
    int prev, curr = 0;
    int first = -1, last = -1;
    for (int i = 0; i < n; ++i) {
        prev = curr;
        cin >> curr;
        if (curr == prev) {
            if (first == -1) {
                first = i;
            } else {
                last = i;
            }
        }
    }
    if (last == -1) {
        return 0;
    } else {
        return (last - first > 2) ? last - first - 1 : 1;
    }
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
