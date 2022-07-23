#include <iostream>
#include <algorithm>

using namespace std;

int ignore(string &s, int left, int right, char c) {
    int ignored = 0;
    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            if (s[left] == c) {
                left++;
                ignored++;
            } else if (s[right] == c) {
                right--;
                ignored++;
            } else {
                return -1;
            }
        }
    }
    return ignored;
}

int solve() {
    int n;
    string s;
    cin >> n >> s;
    int left = 0, right = n - 1;
    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            int leftAns = ignore(s, left, right, s[left]);
            int rightAns = ignore(s, left, right, s[right]);
            if (leftAns == -1) {
                return rightAns;
            } else if (rightAns == -1) {
                return leftAns;
            } else {
                return min(leftAns, rightAns);
            }
        }
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
