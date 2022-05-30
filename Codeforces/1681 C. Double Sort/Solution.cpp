#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sortByA(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

bool sortByB(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

string solve() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int> (3));
    for (int i = 0; i < n; ++i) {
        arr[i][0] = i;
        cin >> arr[i][1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][2];
    }
    sort(arr.begin(), arr.end(), sortByA);
    int prevA = arr[0][1];
    int prevAInd = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i][1] != prevA) {
            sort(arr.begin() + prevAInd, arr.begin() + i, sortByB);
            prevA = arr[i][1];
            prevAInd = i;
        }
    }
    sort(arr.begin() + prevAInd, arr.end(), sortByB);
    for (int i = 1; i < n; ++i) {
        if (arr[i - 1][2] > arr[i][2]) {
            return "-1\n";
        }
    }
    int countMoves = 0;
    string moves;
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        int temp = arr[i][0];
        int targetIndex = -1;
        for (int j = i; j < n; ++j) {
            if (indices[j] == temp) {
                targetIndex = j;
                break;
            }
        }
        if (targetIndex != i) {
            countMoves++;
            moves += to_string(i + 1) + " " + to_string(targetIndex + 1) + "\n";
            indices[targetIndex] = indices[i];
            indices[i] = temp;
        }
    }
    return to_string(countMoves) + "\n" + moves;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solve();
    }
    return 0;
}
