#include <iostream>
#include <vector>

using namespace std;

int solve(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int val = vec[n - 1];
    int pointer = n - 1;
    int total = 0;
    while (pointer > -1) {
        while (pointer > -1 && vec[pointer] == val) {
            pointer--;
        }
        if (pointer > -1) {
            total++;
            pointer -= n - pointer - 1;
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
