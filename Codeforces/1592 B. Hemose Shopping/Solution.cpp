#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solve() {
    int n, x;
    cin >> n >> x;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    vector<int> vecCopy = vec;
    sort(vecCopy.begin(), vecCopy.end());
    for (int i = n - x; i < x; ++i) {
        if (vec[i] != vecCopy[i]) {
            return "NO";
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