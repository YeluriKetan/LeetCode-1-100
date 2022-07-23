#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b > a) {
        return gcd(b, a);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    int n;
    long long ai;
    vector<int> bitCount(30, 0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        for (int j = 0; j < 30; ++j) {
            if (ai <= 0) {
                break;
            } else {
                bitCount[j] += (int) (ai & 1L);
                ai >>= 1;
            }
        }
    }
    int gcdVal = -1;
    for (auto curr: bitCount) {
        if (curr == 0) {
            continue;
        } else {
            if (gcdVal == -1) {
                gcdVal = curr;
            } else {
                gcdVal = gcd(gcdVal, curr);
            }
        }
    }
    if (gcdVal == -1) {
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        for (int i = 1; i <= gcdVal; ++i) {
            if (gcdVal % i == 0) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
