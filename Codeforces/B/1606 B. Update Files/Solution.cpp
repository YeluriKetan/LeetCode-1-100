#include <iostream>

using namespace std;

long long solve() {
    long long n, k, temp = 1, count = 0;
    cin >> n >> k;
    while (temp < n) {
        if (temp < k) {
            temp *= 2;
        } else {
            count += (n - temp - 1) / k + 1;
            break;
        }
        count++;
    }
    return count;
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
