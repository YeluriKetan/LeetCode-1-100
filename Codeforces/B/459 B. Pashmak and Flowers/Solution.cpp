#include <iostream>

using namespace std;

void solve() {
    int n, bi, minVal = INT_MAX, minCount = 0, maxVal = -1, maxCount = 0;
    cin >> n;
    while (n--) {
        cin >> bi;
        if (bi < minVal) {
            minVal = bi;
            minCount = 1;
        } else if (bi == minVal) {
            minCount++;
        }
        if (bi > maxVal) {
            maxVal = bi;
            maxCount = 1;
        } else if (bi == maxVal) {
            maxCount++;
        }
    }
    if (minVal == maxVal) {
        cout << "0 " << (((long long) minCount) * (minCount - 1)) / 2;
    } else {
        cout << maxVal - minVal << " " << ((long long) minCount) * maxCount << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
