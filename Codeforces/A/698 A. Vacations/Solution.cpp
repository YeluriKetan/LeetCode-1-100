#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, temp;
    cin >> n;
    vector<int> options(n + 1), rest(n + 1, 0), gym(n + 1, 0), contest(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> options[i];
    }
    for (int i = 1; i <= n; ++i) {
        temp = i;
        for (int j = i - 1; j > -1; --j) {
            temp = min(temp, rest[j] + i - j);
            temp = min(temp, gym[j] + i - j);
            temp = min(temp, contest[j] + i - j);
        }
        rest[i] = temp;
        if (options[i] > 1) {
            temp = i;
            for (int j = i - 1; j > -1; --j) {
                temp = min(temp, rest[j] + i - j - 1);
                if (j < i - 1) {
                    temp = min(temp, gym[j] + i - j - 1);
                }
                temp = min(temp, contest[j] + i - j - 1);
            }
            gym[i] = temp;
        } else {
            gym[i] = 10000;
        }
        if (options[i] & 1) {
            temp = i;
            for (int j = i - 1; j > -1; --j) {
                temp = min(temp, rest[j] + i - j - 1);
                if (j < i - 1) {
                    temp = min(temp, contest[j] + i - j - 1);
                }
                temp = min(temp, gym[j] + i - j - 1);
            }
            contest[i] = temp;
        } else {
            contest[i] = 10000;
        }
    }
    cout << min(rest[n], min(contest[n], gym[n])) << "\n";
    return 0;
}
