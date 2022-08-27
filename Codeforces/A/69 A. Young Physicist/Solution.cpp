#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, xi, yi, zi, x = 0, y = 0, z = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> xi >> yi >> zi;
        x += xi;
        y += yi;
        z += zi;
    }
    if (x | y | z) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}
