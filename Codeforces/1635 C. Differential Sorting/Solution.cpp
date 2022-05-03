#include <iostream>
#include <vector>

using namespace std;

void solve(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int pointer = n - 2;
    while (pointer > -1 && vec[pointer] <= vec[pointer + 1]) {
        pointer--;
    }
    if (pointer == -1) {
        cout << "0\n";
        return;
    }
    if (pointer == n - 2 || vec[n - 1] < 0) {
        cout << "-1\n";
        return;
    }
    cout << pointer + 1 << "\n";
    while (pointer > -1) {
        cout << pointer + 1 << " " << pointer + 2 << " " << n << "\n";
        pointer--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        solve(n);
    }
    return 0;
}
