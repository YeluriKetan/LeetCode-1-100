#include <iostream>
#include <algorithm>

using namespace std;

int solve() {
    int n;
    int boxes[3][3];
    cin >> n;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> boxes[i][j];
        }
    }
    int count = 0;
    int temp, toBox;
    for (int fromBox = 0; fromBox < 3; ++fromBox) {
        toBox = (fromBox + 1) % 3;
        temp = min(boxes[fromBox][toBox], boxes[toBox][fromBox]);
        if (temp == 0) {
            continue;
        }
        boxes[fromBox][fromBox] += temp;
        boxes[fromBox][toBox] -= temp;
        boxes[toBox][fromBox] -= temp;
        boxes[toBox][toBox] += temp;
        count += temp;
    }
    count += 2 * max(boxes[0][1], boxes[0][2]);
    return count;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solve() << "\n";
    }
    return 0;
}