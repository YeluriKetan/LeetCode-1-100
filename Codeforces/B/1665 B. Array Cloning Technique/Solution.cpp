#include <iostream>
#include <map>

using namespace std;

int solve(int n) {
    map<int, int> counter;
    int curr;
    int maxFreq = 0, temp;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        temp = counter[curr] + 1;
        counter[curr] = temp;
        maxFreq = max(maxFreq, temp);
    }
    int ans = 0;
    n -= maxFreq;
    while (n > 0) {
        ans += 1;
        maxFreq = min(maxFreq, n);
        ans += maxFreq;
        n -= maxFreq;
        maxFreq *= 2;
    }
    return ans;
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