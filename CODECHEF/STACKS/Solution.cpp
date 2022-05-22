#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n, ai, count = 0;
    cin >> n;
    map<int, int> mapping;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        auto it = mapping.upper_bound(ai);
        if (it == mapping.end()) {
            count++;
        } else {
            if (it->second == 1) {
                mapping.erase(it);
            } else {
                it->second--;
            }
        }
        it = mapping.find(ai);
        if (it == mapping.end()) {
            mapping.insert({ai, 1});
        } else {
            it->second++;
        }
    }
    cout << count << " ";
    for (auto & it : mapping) {
        for (int i = it.second; i > 0; --i) {
            cout << it.first << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
