#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve() {
    int n, k, ai, temp1, temp2, pointer;
    long long total = 0;
    cin >> n >> k;
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        if (ai > 0) {
            pos.push_back(ai);
        } else {
            neg.push_back(ai);
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    temp1 = (!pos.empty()) ? pos.back() : 0;
    temp2 = (!neg.empty()) ? -1 * neg.front() : 0;
    if (temp1 > temp2) {
        total += temp2 * 2;
        total += temp1;
    } else {
        total += temp1 * 2;
        total += temp2;
    }
    pointer = pos.size() - 1 - k;
    while (pointer > -1) {
        total += 2 * pos[pointer];
        pointer -= k;
    }
    pointer = k;
    while (pointer < neg.size()) {
        total -= 2 * neg[pointer];
        pointer += k;
    }
    return total;
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
