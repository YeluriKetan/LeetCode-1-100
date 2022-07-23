#include <iostream>
#include <set>

using namespace std;

void solve() {
    int n, m;
    long long ai, sum = 0, xi, yi, currAns, tempAns;
    multiset<long long> ascend;
    multiset<long long> descend;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        sum += ai;
        ascend.insert(ai);
        descend.insert(-1 * ai);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        currAns = LONG_LONG_MAX;
        cin >> xi >> yi;
        auto pointer = ascend.upper_bound(xi);
        tempAns = 0;
        if (pointer != ascend.end()) {
            if (pointer.operator*() < xi) {
                tempAns += xi - pointer.operator*();
            }
            if (sum - pointer.operator*() < yi) {
                tempAns += yi - sum + pointer.operator*();
            }
            if (tempAns < currAns) {
                currAns = tempAns;
            }
        }
        pointer = ascend.lower_bound(xi);
        tempAns = 0;
        if (pointer != ascend.end()) {
            if (pointer.operator*() < xi) {
                tempAns += xi - pointer.operator*();
            }
            if (sum - pointer.operator*() < yi) {
                tempAns += yi - sum + pointer.operator*();
            }
            if (tempAns < currAns) {
                currAns = tempAns;
            }
        }
        tempAns = 0;
        if (pointer != ascend.begin()) {
            pointer.operator--();
            if (pointer.operator*() < xi) {
                tempAns += xi - pointer.operator*();
            }
            if (sum - pointer.operator*() < yi) {
                tempAns += yi - sum + pointer.operator*();
            }
            if (tempAns < currAns) {
                currAns = tempAns;
            }
        }
        cout << currAns << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
