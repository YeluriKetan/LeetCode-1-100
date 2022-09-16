#include "iostream"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, t;
    string s, temp;
    cin >> n >> t >> s;
    while (t--) {
        temp = s;
        for (int i = 1; i < n; ++i) {
            if (s[i] == 'G' && s[i - 1] == 'B') {
                temp[i - 1] = 'G';
                temp[i] = 'B';
            }
        }
        s = temp;
    }
    cout << s << "\n";
    return 0;
}