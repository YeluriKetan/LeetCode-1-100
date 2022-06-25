#include <iostream>

using namespace std;

long long solve() {
    int n;
    string s;
    cin >> n >> s;
    long long total = n;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            total += i;
        }
    }
    return total;
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
