#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    if (a > b) {
        return gcd(b, a % b);
    } else {
        return gcd(a, b % a);
    }
}

long long solve() {
    int n;
    cin >> n;
    vector<long long> vec(n);
    cin >> vec[0] >> vec[1];
    long long gcdEven = vec[0], gcdOdd = vec[1];
    for (int i = 2; i < n; ++i) {
        cin >> vec[i];
        if (i % 2) {
            gcdOdd = gcd(gcdOdd, vec[i]);
        } else {
            gcdEven = gcd(gcdEven, vec[i]);
        }
    }
    bool fail = false;
    for (int i = 0; i < n; i += 2) {
        if (vec[i] % gcdOdd == 0) {
            fail = true;
            break;
        }
    }
    if (fail) {
        fail = false;
    } else {
        return gcdOdd;
    }
    for (int i = 1; i < n; i += 2) {
        if (vec[i] % gcdEven == 0) {
            fail = true;
            break;
        }
    }
    if (fail) {
        return 0;
    } else {
        return gcdEven;
    }
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
