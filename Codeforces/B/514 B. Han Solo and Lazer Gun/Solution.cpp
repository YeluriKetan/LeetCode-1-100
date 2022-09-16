#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, x0, y0, vertical = 0; cin >> n >> x0 >> y0;
    double xi, yi;
    unordered_set<double> slopes;
    while (n--) {
        cin >> xi >> yi;
        if (xi == x0) {
            vertical++;
        } else {
            slopes.insert((yi - y0) / (xi - x0));
        }
    }
    cout << slopes.size() + (vertical > 0 ? 1 : 0) << "\n";
    return 0;
}