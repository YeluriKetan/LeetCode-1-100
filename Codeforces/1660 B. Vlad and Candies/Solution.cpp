#include <iostream>

using namespace std;

string solve(int n) {
    int highest = 0, nextHighest = -1, curr;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (curr > highest) {
            nextHighest = highest;
            highest = curr;
        } else if (curr > nextHighest) {
            nextHighest = curr;
        }
    }
    return highest - nextHighest < 2 ? "YES" : "NO";
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
