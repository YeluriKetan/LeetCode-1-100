#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n, q, ai, same = 0, type, index, x;
    long long sum = 0;
    cin >> n >> q;
    map<int, int> elements;
    for (int i = 1; i <= n; ++i) {
        cin >> ai;
        sum += ai;
        elements[i] = ai;
    }
    for (int i = 0; i < q; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> index;
        }
        cin >> x;
        if (type == 1) {
            if (elements.find(index) == elements.end()) {
                sum += x - same;
            } else {
                sum += x - elements[index];
            }
            elements[index] = x;
        } else {
            elements.clear();
            same = x;
            sum = x;
            sum *= n;
        }
        cout << sum << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
