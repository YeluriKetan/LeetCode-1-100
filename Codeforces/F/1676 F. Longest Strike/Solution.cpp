#include <iostream>
#include <map>

using namespace std;

string solve() {
    int n, k, ai;
    cin >> n >> k;
    map<int, int> counter;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        counter[ai]++;
    }
    int maxLen = 0, maxStart = -1, currStart = -1, currEnd = -2;
    for (auto curr: counter) {
        if (curr.second >= k) {
            if (currEnd + 1 == curr.first) {
                currEnd++;
                if (currEnd - currStart + 1 > maxLen) {
                    maxLen = currEnd - currStart + 1;
                    maxStart = currStart;
                }
            } else {
                currStart = currEnd = curr.first;
            }
        }
    }
    if (currEnd - currStart + 1 > maxLen) {
        maxLen = currEnd - currStart + 1;
        maxStart = currStart;
    }
    if (!maxLen) {
        return "-1";
    } else {
        return to_string(maxStart) + " " + to_string(maxStart + maxLen - 1);
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
