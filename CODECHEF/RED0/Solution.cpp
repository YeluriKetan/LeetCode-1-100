#include <iostream>

using namespace std;

long long solve() {
    long long x, y, result;
    cin >> x >> y;
    if (x == y) {
        return x;
    } else {
        if (x == 0 || y == 0) {
            return -1;
        }
        if (x > y) {
            swap(x, y);
        }
        result = 0;
        while (x < y - x) {
            x *= 2;
            result++;
        }
        return result + y + 1;
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
