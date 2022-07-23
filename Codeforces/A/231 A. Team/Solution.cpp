#include <iostream>

using namespace std;

int solve() {
    int n, temp, currSum, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        currSum = 0;
        for (int j = 0; j < 3; ++j) {
            cin >> temp;
            currSum += temp;
        }
        if (currSum > 1) {
            ans++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
