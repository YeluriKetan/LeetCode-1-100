#include <iostream>

using namespace std;

void solve(int n) {
    int low = INT_MAX, lowInd = -1, high = -1, highInd = -1, curr = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> curr;
        if (curr < low) {
            low = curr;
            lowInd = i;
        }
        if (curr > high) {
            high = curr;
            highInd = i;
        }
    }
    cout << lowInd << " " << highInd << "\n";
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        solve(n);
    }
}
