#include <iostream>

using namespace std;

long long solve(int n) {
    long long totalSum = 0;
    int oneCount = 0;
    int curr;
    cin >> curr;
    if (n == 3) {
        cin >> curr;
        if (curr % 2 == 0) {
            totalSum = curr / 2;
        } else {
            oneCount = 1;
        }
    } else {
        for (int i = 1; i < n - 1; ++i) {
            cin >> curr;
            if (curr == 1) {
                oneCount++;
            }
            totalSum += (curr + 1) / 2;
        }
    }
    cin >> curr;
    if (oneCount < n - 2) {
        return totalSum;
    } else {
        return -1;
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
