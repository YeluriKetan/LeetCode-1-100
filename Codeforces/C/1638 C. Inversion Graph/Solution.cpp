#include <iostream>

using namespace std;

int solve() {
    int n, ai, currMax = 0, componentCount = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> ai;
        if (ai > currMax) {
            currMax = ai;
        }
        if (i == currMax) {
            componentCount++;
        }
    }
    return componentCount;
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
