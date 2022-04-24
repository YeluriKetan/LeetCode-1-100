#include <iostream>
#include <vector>

using namespace std;

int solve(int n) {
    vector<int> vec(n + 1);
    vec[0] = 0;
    int total = 0, curr;
    for (int i = 1; i <= n; ++i) {
        cin >> curr;
        total += curr;
        vec[i] = total;
    }
    total = 0;
    int left = 0;
    int maxCandies = 0;
    for (int i = n; i > 0; --i) {
        total += vec[i] - vec[i - 1];
        while (left < i && vec[left] < total) {
            left++;
        }
        if (left >= i) {
            break;
        } else if (total == vec[left]) {
            maxCandies = left + n - i + 1;
        }
    }
    return maxCandies;
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
