#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, bi; cin >> n;
    long long total = 0;
    vector<int> topics(n);
    for (int i = 0; i < n; ++i) {
        cin >> topics[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> bi;
        topics[i] -= bi;
    }
    sort(topics.begin(), topics.end());
    int left = 0, right = n - 1;
    while (left < n - 1) {
        right = max(right, left + 1);
        while (left < right) {
            if (topics[left] + topics[right] > 0) {
                right--;
            } else {
                break;
            }
        }
        total += n - 1 - right;
        left++;
    }
    cout << total << "\n";
    return 0;
}
