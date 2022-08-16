#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, totalMoves = 0, aTotal = 0, bTotal = 0, prevSum = 0, currSum, left = 0, right;
    bool moved = false;
    cin >> n;
    vector<int> candies(n);
    for (int i = 0; i < n; ++i) {
        cin >> candies[i];
    }
    right = n - 1;
    while (true) {
        currSum = 0;
        while (left <= right && currSum <= prevSum) {
            currSum += candies[left++];
            moved = true;
        }
        aTotal += currSum;
        if (moved) {
            moved = false;
            totalMoves++;
        }
        if (currSum > prevSum) {
            prevSum = currSum;
        } else {
            break;
        }
        currSum = 0;
        while (left <= right && currSum <= prevSum) {
            currSum += candies[right--];
            moved = true;
        }
        bTotal += currSum;
        if (moved) {
            moved = false;
            totalMoves++;
        }
        if (currSum > prevSum) {
            prevSum = currSum;
        } else {
            break;
        }
    }
    cout << totalMoves << " " << aTotal << " " << bTotal << "\n";
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
