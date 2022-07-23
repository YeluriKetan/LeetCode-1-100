#include <iostream>
#include <vector>

using namespace std;

int solve() {
    int n, m, bi;
    cin >> n;
    vector<int> deck(n);
    for (int i = 0; i < n; ++i) {
        cin >> deck[i];
    }
    cin >> m;
    int currTop = 0;
    for (int i = 0; i < m; ++i) {
        cin >> bi;
        currTop = (currTop + bi) % n;
    }
    return deck[currTop];
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
