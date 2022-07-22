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

string solve() {
    int n, ai, red = 0, blue = 0;
    string s;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        vec[i] = {ai, i};
    }
    cin >> s;
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 1; i <= n; ++i) {
        while (blue < n && s[vec[blue].second] != 'B') {
            blue++;
        }
        if (blue != n) {
            if (vec[blue].first >= i) {
                blue++;
                continue;
            } else {
                return "NO";
            }
        }
        while (red < n && s[vec[red].second] != 'R') {
            red++;
        }
        if (red == n) {
            return "NO";
        } else {
            if (vec[red].first <= i) {
                red++;
                continue;
            } else {
                return "NO";
            }
        }
    }
    return "YES";
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
