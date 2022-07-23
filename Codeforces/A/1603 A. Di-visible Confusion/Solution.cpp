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

string solve() {
    int n, ai, den = 1;
    cin >> n;
    vector<int> vec(21);
    for (int i = 0; i < n; ++i) {
        if (i < 21) {
            cin >> vec[i];
        } else {
            cin >> ai;
        }
    }
    for (int i = 2; i < min(n + 2, 23); ++i) {
        den *= i / gcd(den, i);
        if (vec[i - 2] % den == 0) {
            return "NO";
        }
    }
    return "YES";
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
