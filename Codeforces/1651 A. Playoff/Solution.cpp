#include <iostream>
#include <cmath>

using namespace std;

int solve(int n) {
    return (int) pow(2, n) - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
