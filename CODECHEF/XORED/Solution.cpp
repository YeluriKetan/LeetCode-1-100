#include <iostream>

using namespace std;

int arr[100000];

void print(int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void solve(int n, int x) {
    int curr = 0;
    for (int i = 0; i < n - 1; ++i) {
        curr ^= i;
    }
    curr ^= x;
    if (curr < (n - 1)) {
        arr[n - 1] = 131072 + curr;
        if (curr == 0) {
            arr[1] += 131072;
            print(n);
            arr[1] = 1;
        } else {
            arr[0] += 131072;
            print(n);
            arr[0] = 0;
        }
        arr[n - 1] = n - 1;
    } else if (curr > 500000) {
        arr[0] = curr & 393216;
        arr[n - 1] = curr - arr[0];
        print(n);
        arr[n - 1] = n - 1;
        arr[0] = 0;
    } else {
        arr[n - 1] = curr;
        print(n);
        arr[n - 1] = n - 1;
    }
}

int main() {
    for (int i = 0; i < 100000; ++i) {
        arr[i] = i;
    }
    int t, n, x;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> x;
        solve(n, x);
    }
    return 0;
}
