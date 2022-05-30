#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool defeated(vector<long long> &vec, long long h, long long k) {
    for (auto currDiff: vec) {
        h -= min(currDiff, k);
        if (h < 1) {
            return true;
        }
    }
    return h < 1;
}

long long solve() {
    int n, prevAi, ai;
    long long h;
    cin >> n >> h;
    vector<long long> vec(n);
    cin >> ai;
    for (int i = 0; i < n - 1; ++i) {
        prevAi = ai;
        cin >> ai;
        vec[i] = ai - prevAi;
    }
    vec[n - 1] = 1000000000000000000;
    long long low = 1, high = 1000000000000000000, mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (defeated(vec, h, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
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
