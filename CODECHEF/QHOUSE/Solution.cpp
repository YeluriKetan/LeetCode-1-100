#include <iostream>

using namespace std;

int solve() {
    int low = 2, high = 1000, mid;
    string s;
    while (low < high) {
        mid = (low + high) / 2;
        if (mid == low) {
            cout << "? 0 " << mid + 1 << endl;
            cin >> s;
            if (s == "YES") {
                low = mid + 1;
            }
            break;
        }
        cout << "? 0 " << mid << endl;
        cin >> s;
        if (s == "YES") {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    int peak = low;
    low = 1, high = 1000;
    while (low < high) {
        mid = (low + high) / 2;
        if (mid == low) {
            cout << "? " << mid + 1 << " 0" << endl;
            cin >> s;
            if (s == "YES") {
                low = mid + 1;
            }
            break;
        }
        cout << "? " << mid << " 0" << endl;
        cin >> s;
        if (s == "YES") {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    int houseBorder = low;
    low = houseBorder + 1, high = 1000;
    while (low < high) {
        mid = (low + high) / 2;
        if (mid == low) {
            cout << "? " << mid + 1 << " " << 2 * houseBorder << endl;
            cin >> s;
            if (s == "YES") {
                low = mid + 1;
            }
            break;
        }
        cout << "? " << mid << " " << 2 * houseBorder << endl;
        cin >> s;
        if (s == "YES") {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return (peak - 2 * houseBorder) * (low) + (2 * houseBorder) * (2 * houseBorder);
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << "! " << solve() << endl;
    return 0;
}
