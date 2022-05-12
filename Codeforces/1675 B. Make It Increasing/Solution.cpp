#include <iostream>
#include <vector>

using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int total = 0;
    for (int i = n - 2; i > -1; --i) {
        if (!vec[i + 1]) {
            return -1;
        }
        while (vec[i] != 0 && vec[i] >= vec[i + 1]) {
            vec[i] /= 2;
            total++;
        }
    }
    return total;
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
