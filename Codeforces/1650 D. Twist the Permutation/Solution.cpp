#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int left = 0, di, found;
    for (int i = n; i > 0; --i) {
        di = 0, found = -1;
        for (int j = left; j < n; ++j) {
            if (vec[j] == i) {
                found = j;
                di++;
                break;
            } else if (vec[j] > i) {
                continue;
            } else {
                di++;
            }
        }
        if (found != -1) {
            ans[i - 1] = (di % i);
            left = (found + 1) % n;
            continue;
        }
        for (int j = 0; j < left; ++j) {
            if (vec[j] == i) {
                found = j;
                di++;
                break;
            } else if (vec[j] > i) {
                continue;
            } else {
                di++;
            }
        }
        ans[i - 1] = (di % i);
        left = (found + 1) % n;
    }
    for (auto curr: ans) {
        cout << curr << " ";
    }
    cout << "\n";
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
