#include <iostream>
#include <cmath>

using namespace std;

int solve(int x, int y) {
    if (x + y == 0) {
        return 0;
    }
    double val = sqrt(x * x + y * y);
    if (val == floor(val)) {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    int t, x, y;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
}
