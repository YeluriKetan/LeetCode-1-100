#include <iostream>

using namespace std;

void solve(int n) {
    switch (n % 3) {
        case 0: {
            for (int i = n; i > 0; i -= 3) {
                cout << "21";
            }
            cout << "\n";
            break;
        }
        case 1: {
            cout << "1";
            for (int i = n - 1; i > 0; i -= 3) {
                cout << "21";
            }
            cout << "\n";
            break;
        }
        case 2: {
            for (int i = n - 2; i > 0; i -= 3) {
                cout << "21";
            }
            cout << "2\n";
            break;
        }
        default:
            break;
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
