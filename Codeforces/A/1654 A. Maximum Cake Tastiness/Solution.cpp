#include <iostream>

using namespace std;

int solve(int n) {
    int highest = 0, nextHighest = 0, curr;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (curr > highest) {
            nextHighest = highest;
            highest = curr;
        } else if (curr > nextHighest) {
            nextHighest = curr;
        }
    }
    return highest + nextHighest;
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
