#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    int count = 0;
    while (n > 0) {
        if (n % 10 == 4 || n % 10 == 7) {
            count++;
        }
        n /= 10;
    }
    if (count == 0) {
        cout << "NO\n";
        return 0;
    }
    while (count > 0) {
        if (count % 10 != 4 && count % 10 != 7) {
            cout << "NO\n";
            return 0;
        }
        count /= 10;
    }
    cout << "YES\n";
    return 0;
}