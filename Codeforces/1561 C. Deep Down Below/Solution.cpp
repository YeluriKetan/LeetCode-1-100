#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int solve() {
    int n, ki, aij, curr, prev = 0, ans = 0;
    cin >> n;
    vector<pair<int, int>> caves(n);
    for (int i = 0; i < n; ++i) {
        cin >> ki;
        curr = 0;
        for (int j = 0; j < ki; ++j) {
            cin >> aij;
            if (curr <= aij) {
                curr = aij + 1;
            }
            curr++;
        }
        curr -= ki;
        caves[i] = {curr, ki};
    }
    sort(caves.begin(), caves.end(), cmp);
    for (auto currCave : caves) {
        if (prev < currCave.first) {
            ans += currCave.first - prev;
            prev = currCave.first + currCave.second;
        } else {
            prev += currCave.second;
        }
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
