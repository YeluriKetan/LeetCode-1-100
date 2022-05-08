#include <iostream>
#include <cmath>

using namespace std;

string solve() {
    long long hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    double leftVal, rightVal;
    for (long long k1 = k; k1 > -1; --k1) {
        leftVal = hc + a * k1;
        leftVal = ceil(leftVal / dm);
        rightVal = dc + w * k - w * k1;
        rightVal = ceil(hm / rightVal);
        if (leftVal >= rightVal) {
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
