#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    double r, x, y, X, Y, temp; cin >> r >> x >> y >> X >> Y;
    temp = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
    cout << (int) ceil(temp / (2 * r)) << "\n";
    return 0;
}
