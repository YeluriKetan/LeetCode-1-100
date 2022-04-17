#include <iostream>

using namespace std;

int solve(long long n, long long s) {
    return s / (n * n);
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    long long n, s;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> s;
        cout << solve(n, s) << "\n";
    }
    return 0;
}
