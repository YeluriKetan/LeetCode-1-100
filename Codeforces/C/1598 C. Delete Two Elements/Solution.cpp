#include <iostream>
#include <map>

using namespace std;

long long solve() {
    int n, ai;
    long long sum = 0, count = 0;
    double k;
    cin >> n;
    map<int, int> counterMap;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        sum += ai;
        counterMap[ai]++;
    }
    if (!(sum % n == 0 || (sum * 2) % n == 0)) {
        return 0;
    }
    k = ((double) sum) / n;
    for (auto curr: counterMap) {
        if (curr.first >= k) {
            break;
        }
        count += ((long long) curr.second) * counterMap[(int) (2 * k - curr.first)];
    }
    if (k - (int) k == 0) {
        auto pointer = counterMap.find((int) k);
        if (pointer != counterMap.end()) {
            count += (((long long) (pointer->second)) * (pointer->second - 1)) / 2;
        }
    }
    return count;
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
