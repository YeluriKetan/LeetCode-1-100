#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, curr, temp, maxVal = 1; cin >> n;
    vector<int> a(n + 1), operCount(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        a[curr] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (a[curr] < i) {
            temp = n + a[curr] - i;
        } else {
            temp = a[curr] - i;
        }
        operCount[temp]++;
    }
    for (auto currCount: operCount) {
        maxVal = max(maxVal, currCount);
    }
    cout << maxVal << "\n";
    return 0;
}
