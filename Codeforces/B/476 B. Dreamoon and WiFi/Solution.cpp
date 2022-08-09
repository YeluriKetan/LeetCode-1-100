#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s1, s2;
    cin >> s1 >> s2;
    int actual = 0, temp, count = 0, total;
    for (auto currChar: s1) {
        if (currChar == '+') {
            actual++;
        } else {
            actual--;
        }
    }
    queue<int> possibilities;
    possibilities.push(0);
    for (auto currChar: s2) {
        for (int i = possibilities.size(); i > 0; --i) {
            temp = possibilities.front();
            possibilities.pop();
            if (currChar != '+') {
                possibilities.push(temp - 1);
            }
            if (currChar != '-') {
                possibilities.push(temp + 1);
            }
        }
    }
    total = possibilities.size();
    for (int i = total; i > 0; --i) {
        temp = possibilities.front();
        possibilities.pop();
        if (actual == temp) {
            count++;
        }
    }
    double ans = count;
    ans /= total;
    printf("%.12lf", ans);
    return 0;
}
