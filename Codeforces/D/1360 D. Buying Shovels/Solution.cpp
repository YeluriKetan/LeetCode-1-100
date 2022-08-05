#include <iostream>
#include <cmath>

using namespace std;

int solve() {
    int n, k, numOfPackages;
    cin >> n >> k;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            if (n / i <= k) {
                return i;
            } else {
                if (i <= k) {
                    numOfPackages = n / i;
                }
            }
        }
    }
    return numOfPackages;
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
