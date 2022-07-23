#include <iostream>

using namespace std;

int solve(int a, int b) {
    return (a == 0) ? 1 : a + 2 * b + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, a, b;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
    return 0;
}
