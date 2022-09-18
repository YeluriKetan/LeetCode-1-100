#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

long long solve() {
    int n, k; cin >> n >> k;
    long long ans = 0;
    vector<int> vec(n), counter(k);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> counter[i];
    }
    sort(vec.begin(), vec.end());
    sort(counter.begin(), counter.end());
    int pointer = n - 1;
    for (auto currCount: counter) {
        if (currCount == 1) {
            ans += 2 * vec[pointer--];
        } else {
            ans += vec[pointer--];
        }
    }
    for (auto currCount: counter) {
        if (currCount == 1) {
            continue;
        }
        pointer -= currCount - 2;
        ans += vec[pointer--];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}