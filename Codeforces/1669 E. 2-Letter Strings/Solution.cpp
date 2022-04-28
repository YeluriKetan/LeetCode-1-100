#include <iostream>

using namespace std;

long long solve(int n) {
    int leftCount[11] = {0};
    int rightCount[11] = {0};
    int stringCount[121] = {0};
    string curr;
    long long totalCount = 0;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        totalCount += leftCount[curr[0] - 'a']++;
        totalCount += rightCount[curr[1] - 'a']++;
        totalCount -= 2 * stringCount[((curr[0] - 'a') * 11) + (curr[1] - 'a')]++;
    }
    return totalCount;
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
