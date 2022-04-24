#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solve(int n, int x) {
    map<long long, int> counter;
    long long curr;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        counter[curr]++;
    }
    int total = 0, temp;
    long long target;
    for (auto currPair: counter) {
        if (!currPair.second) {
            continue;
        }
        target = currPair.first * x;
        temp = min(currPair.second, counter[target]);
        if (temp) {
            counter[target] -= temp;
        }
        total += currPair.second - temp;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n, x;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> x;
        cout << solve(n, x) << "\n";
    }
    return 0;
}
