#include <iostream>

using namespace std;

int solve() {
    int a, temp, count = 0;
    cin >> a;
    for (int i = 0; i < 3; ++i) {
        cin >> temp;
        if (temp > a) {
            count++;
        }
    }
    return count;
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
