#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
    int n;
    long long ai, maxAi = -1, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        sum += ai;
        maxAi = max(maxAi, ai);
    }
    sum -= maxAi;
    if (!maxAi) {
        return 0;
    } else {
        return (int) (maxAi > sum ? maxAi - sum : 1);
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
