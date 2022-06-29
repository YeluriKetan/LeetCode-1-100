#include <iostream>
#include <set>

using namespace std;

int solve() {
    int n, ai, duplicates = 0;
    set<int> present;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        if (present.find(ai) == present.end()) {
            present.insert(ai);
        } else {
            duplicates++;
        }
    }
    if (duplicates % 2) {
        return n - duplicates - 1;
    } else {
        return n - duplicates;
    }
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
