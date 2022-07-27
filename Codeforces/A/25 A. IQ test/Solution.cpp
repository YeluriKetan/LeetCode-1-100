#include <iostream>

using namespace std;

int solve() {
    int n, ai, oddCount = 0, oddIndex = -1, evenIndex = -1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> ai;
        if (ai % 2) {
            oddCount++;
            oddIndex = i;
        } else {
            evenIndex = i;
        }
    }
    return (oddCount == 1) ? oddIndex : evenIndex;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
