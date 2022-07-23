#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solve() {
    int n, ai, pointer = 0;
    cin >> n;
    set<int> uniq;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        if (ai <= n && uniq.find(ai) == uniq.end()) {
            uniq.insert(ai);
        } else {
            vec.push_back(ai);
        }
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= n; ++i) {
        if (uniq.find(i) != uniq.end()) {
            continue;
        } else {
            if ((vec[pointer] - 1) / 2 < i) {
                return -1;
            } else {
                pointer++;
            }
        }
    }
    return n - uniq.size();
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
