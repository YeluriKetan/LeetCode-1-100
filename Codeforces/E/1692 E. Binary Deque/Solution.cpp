#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
    int n, s, temp, maxSum, minOper;
    vector<int> vec;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        if (temp) {
            vec.push_back(i);
        }
    }
    maxSum = vec.size();
    if (s > maxSum) {
        return -1;
    } else if (s == maxSum) {
        return 0;
    }
    s = maxSum - s;
    minOper = n - vec[maxSum - s] + 1;
    for (int i = 0; i < s - 1; ++i) {
        minOper = min(minOper, vec[i] + n - vec[maxSum - s + i + 1] + 1);
    }
    minOper = min(minOper, vec[s - 1]);
    return minOper;
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
