#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> &vec, int n, int q) {
    int low = 0, high = n - 1, mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (low == mid) {
            if (vec[mid + 1] >= q) {
                low = mid + 1;
            }
            break;
        }
        if (vec[mid] >= q) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return vec[low] >= q ? n - low : -1;
}

void solve() {
    int n, q, currQ;
    cin >> n >> q;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (int i = n - 2; i > -1; --i) {
        vec[i] += vec[i + 1];
    }
    for (int i = 0; i < q; ++i) {
        cin >> currQ;
        cout << binarySearch(vec, n, currQ) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
