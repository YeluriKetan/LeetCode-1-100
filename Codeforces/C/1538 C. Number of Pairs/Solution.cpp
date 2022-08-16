#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int left = n - 1, right = n - 1;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        left = max(i, left);
        right = max(left, right);
        while (left > i) {
            if (l <= vec[i] + vec[left]) {
                left--;
            } else {
                break;
            }
        }
        while (right > left) {
            if (vec[i] + vec[right] > r) {
                right--;
            } else {
                break;
            }
        }
        ans += right - left;
    }
    return ans;
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
