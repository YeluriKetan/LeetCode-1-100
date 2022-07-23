#include <iostream>
#include <vector>

using namespace std;

bool isPalindromeWithIgnore(vector<int> &vec, int left, int right, int ignore) {
    while (left < right) {
        if (vec[left] == ignore) {
            left++;
        } else if (vec[right] == ignore) {
            right--;
        } else if (vec[left] != vec[right]) {
            return false;
        } else {
            left++;
            right--;
        }
    }
    return true;
}

string solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int left = 0, right = n - 1;
    while (left < right) {
        if (vec[left] != vec[right]) {
            if (isPalindromeWithIgnore(vec, left + 1, right, vec[left]) || isPalindromeWithIgnore(vec, left, right - 1, vec[right])) {
                return "YES";
            } else {
                return "NO";
            }
        } else {
            left++;
            right--;
        }
    }
    return "YES";
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
