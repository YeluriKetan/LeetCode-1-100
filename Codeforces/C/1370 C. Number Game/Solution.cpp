#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n; cin >> n;
    int evenFactors = 0, oddFactors = 0;
    while (n % 2 == 0) {
        n /= 2;
        evenFactors++;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            n /= i;
            oddFactors++;
        }
    }
    if (n > 1) {
        oddFactors++;
    }
    if (oddFactors == 0) {
        if (evenFactors == 1) {
            return "Ashishgup";
        } else {
            return "FastestFinger";
        }
    } else if (oddFactors == 1) {
        if (evenFactors == 1) {
            return "FastestFinger";
        } else {
            return "Ashishgup";
        }
    } else {
        return "Ashishgup";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}
