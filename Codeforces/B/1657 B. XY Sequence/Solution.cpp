#include <iostream>

using namespace std;

long long solve(int n, int B, int x, int y) {
    long long sum = 0, curr = 0;
    for (int i = 0; i < n; ++i) {
        if (curr + x > B) {
            curr -= y;
        } else {
            curr += x;
        }
        sum += curr;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n, B, x, y;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> B >> x >> y;
        cout << solve(n, B, x, y) << "\n";
    }
    return 0;
}
