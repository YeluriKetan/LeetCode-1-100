#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, t, maxBooks = 0;
    cin >> n >> t;
    vector<int> books(n);
    for (int i = 0; i < n; ++i) {
        cin >> books[i];
    }
    int currSum = 0, right = n - 1;
    for (int i = n - 1; i > -1; --i) {
        currSum += books[i];
        while (currSum > t && right >= i) {
            currSum -= books[right--];
        }
        maxBooks = max(maxBooks, right - i + 1);
    }
    cout << maxBooks << "\n";
    return 0;
}
