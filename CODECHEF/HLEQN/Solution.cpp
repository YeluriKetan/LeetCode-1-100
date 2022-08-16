#include <iostream>
#include <cmath>

using namespace std;

string solve() {
    int x, temp;
    cin >> x;
    if (x < 5) {
        return "NO";
    }
    for (int i = 1; i <= sqrt(x); i++) {
        temp = x - 2 * i;
        if (temp % (2 + i) == 0) {
            return "YES";
        }
    }
    return "NO";
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
