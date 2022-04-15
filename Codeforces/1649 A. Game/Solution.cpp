#include <iostream>

using namespace std;

int solve(int n) {
    int start = -1;
    int curr;
    int consec = 0;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (curr == 0) {
            if (start == -1) {
                start = i - 1;
            }
            consec = 0;
        } else {
            consec++;
        }
    }
    if (start == -1) {
        return 0;
    }
    return n - consec - start;
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
