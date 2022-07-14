#include <iostream>
#include <algorithm>

using namespace std;

int numOfIthBit(int n, int i) {
    i = 1 << (i - 1);
    int temp = n / i + 1;
    if (temp % 2) {
        return (temp / 2) * i;
    } else {
        return ((temp / 2) * i) - (temp * i - 1) + n;
    }
}

int solve() {
    int l, r, maxCount = 0;
    cin >> l >> r;
    for (int i = 1; i < 19; ++i) {
        maxCount = max(maxCount, numOfIthBit(r, i) - numOfIthBit(l - 1, i));
    }
    return r - l + 1 - maxCount;
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
