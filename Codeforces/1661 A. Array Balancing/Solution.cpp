#include <iostream>

using namespace std;

int arr[25];

long long solve(int n) {
    int curr;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        arr[i] = curr;
    }
    int b;
    cin >> b;
    long long total = 0;
    for (int i = 1; i < n; ++i) {
        cin >> curr;
        if (abs(arr[i] - arr[i - 1]) + abs(curr - b) < abs(arr[i] - b) + abs(curr - arr[i - 1])) {
            total += abs(arr[i] - arr[i - 1]) + abs(curr - b);
            b = curr;
        } else {
            total += abs(arr[i] - b) + abs(curr - arr[i - 1]);
            b = arr[i];
            arr[i] = curr;
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
