#include <iostream>

using namespace std;

int solve() {
    int arr[6];
    for (int & i : arr) {
        cin >> i;
    }
    if (arr[1] == arr[3] && arr[5] < arr[1]) {
        return abs(arr[0] - arr[2]);
    }
    if (arr[3] == arr[5] && arr[1] < arr[3]) {
        return abs(arr[2] - arr[4]);
    }
    if (arr[5] == arr[1] && arr[3] < arr[1]) {
        return abs(arr[4] - arr[0]);
    }
    return 0;
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
