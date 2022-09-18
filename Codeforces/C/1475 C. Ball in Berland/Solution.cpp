#include "iostream"
#include "vector"

using namespace std;

long long solve() {
    int a, b, k, temp; cin >> a >> b >> k;
    vector<int> aCount(a, 0), bCount(b, 0);
    vector<pair<int, int>> pairs(k, {0, 0});
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        cin >> temp;
        pairs[i].first = temp - 1;
    }
    for (int i = 0; i < k; ++i) {
        cin >> temp;
        temp--;
        aCount[pairs[i].first]++;
        bCount[temp]++;
        pairs[i].second = temp;
    }
    for (auto &[currA, currB]: pairs) {
        ans += k - aCount[currA] - bCount[currB] + 1;
    }
    return ans / 2;
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