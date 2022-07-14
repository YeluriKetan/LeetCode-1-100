#include <iostream>

using namespace std;

long long numOfMsg(long long x, long long k) {
    long long ans = 0;
    if (x <= k) {
        ans = (x * (x + 1)) / 2;
    } else {
        ans = k * k;
        x = 2 * k - 1 - x;
        x = (x * (x + 1)) / 2;
        ans -= x;
    }
    return ans;
}

long long solve() {
    long long k, x, low, high, mid, temp;
    cin >> k >> x;
    low = 1, high = 2 * k - 1;
    while (low < high) {
        mid = low + (high - low) / 2;
        temp = numOfMsg(mid, k);
        if (temp < x) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
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
