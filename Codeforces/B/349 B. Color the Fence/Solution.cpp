#include "bits/stdc++.h"
using namespace std;

void solve() {
    int v, minPaint = INT_MAX, minPaintDigit = 0; cin >> v;
    vector<int> digits(9);
    for (int i = 0; i < 9; ++i) {
        cin >> digits[i];
        if (digits[i] <= minPaint) {
            minPaint = digits[i];
            minPaintDigit = i + 1;
        }
    }
    int numOfDigits = v / minPaint, extra = v % minPaint;
    if (numOfDigits == 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < numOfDigits; ++i) {
        if (extra) {
            for (int j = 8; j >= 0; --j) {
                if (digits[j] - minPaint <= extra) {
                    cout << j + 1;
                    extra -= digits[j] - minPaint;
                    break;
                }
            }
        } else {
            cout << minPaintDigit;
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}