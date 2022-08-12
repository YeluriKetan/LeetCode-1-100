#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    vector<bool> oddCount(26, false);
    int oddCountOfOddCount = 0, currIndex;
    string s;
    cin >> s;
    for (auto currChar: s) {
        currIndex = currChar - 'a';
        oddCount[currIndex] = !oddCount[currIndex];
    }
    for (auto currOddCount: oddCount) {
        if (currOddCount) {
            oddCountOfOddCount++;
        }
    }
    if (oddCountOfOddCount == 0 || oddCountOfOddCount % 2) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
    return 0;
}
