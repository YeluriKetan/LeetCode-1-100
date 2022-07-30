#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

void solve() {
    int n, intXi;
    double xi;
    bool flag;
    cin >> n;
    unordered_set<int> seenPrimes({1, 2, 3, 5});
    while (n--) {
        cin >> xi;
        if (xi < 4) {
            cout << "NO\n";
            continue;
        }
        xi = sqrt(xi);
        if (xi != (int) xi) {
            cout << "NO\n";
            continue;
        }
        intXi = xi;
        if (seenPrimes.find(intXi) != seenPrimes.end()) {
            cout << "YES\n";
            continue;
        }
        if (intXi % 2 == 0) {
            cout << "NO\n";
            continue;
        }
        flag = false;
        for (int i = 3; i <= sqrt(intXi); i += 2) {
            if (intXi % i == 0) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "NO\n";
        } else {
            seenPrimes.insert(intXi);
            cout << "YES\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
