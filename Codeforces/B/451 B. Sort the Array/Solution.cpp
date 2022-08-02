#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int left = 0, right = n - 1;
    while (left < n - 1) {
        if (vec[left] < vec[left + 1]) {
            left++;
        } else {
            break;
        }
    }
    while (right > 0) {
        if (vec[right - 1] < vec[right]) {
            right--;
        } else {
            break;
        }
    }
    if (right <= left) {
        cout << "yes\n1 1\n";
        return;
    }
    reverse(vec.begin() + left, vec.begin() + right + 1);
    int pointer = 0;
    while (pointer < n - 1) {
        if (vec[pointer] < vec[pointer + 1]) {
            pointer++;
            continue;
        } else {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n" << left + 1 << " " << right + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}