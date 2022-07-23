#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k = 0;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    string ans;
    int leftBound = 0, prev = -1, minIndex, minVal, minCurrD, currD;
    while (leftBound < n - 1) {
        minIndex = -1;
        minVal = INT_MAX;
        currD = 0;
        minCurrD = n;
        for (int i = prev + 1; i < n; ++i) {
            if (vec[i] < minVal) {
                minIndex = i;
                minVal = vec[i];
                minCurrD = currD;
            }
            if (vec[i] != INT_MAX) {
                currD++;
            }
        }
        for (int i = 0; i < prev; ++i) {
            if (vec[i] < minVal) {
                minVal = vec[i];
                minIndex = i;
                minCurrD = currD;
            }
            if (vec[i] != INT_MAX) {
                currD++;
            }
        }
        if (minCurrD != 0) {
            ans += to_string(leftBound + 1) + " " + to_string(n) + " " + to_string(minCurrD) + "\n";
            k++;
        }
        leftBound++;
        prev = minIndex;
        vec[minIndex] = INT_MAX;
    }
    cout << k << "\n" << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
