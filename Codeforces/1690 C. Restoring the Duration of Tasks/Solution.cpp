#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, temp, prevEnd = -1;
    cin >> n;
    vector<int> start(n);
    for (int i = 0; i < n; ++i) {
        cin >> start[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (prevEnd > start[i]) {
            cout << temp - prevEnd << " ";
        } else {
            cout << temp - start[i] << " ";
        }
        prevEnd = temp;
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
