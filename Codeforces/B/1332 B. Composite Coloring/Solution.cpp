#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
using namespace std;

string solve() {
    int N, M = 0, ai; cin >> N;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}, color(11, 0);
    string ans;
    while (N--) {
        cin >> ai;
        for (int i = 0; i < 11; ++i) {
            if (ai % primes[i] == 0) {
                if (!color[i]) color[i] = ++M;
                ans += to_string(color[i]) + " ";
                break;
            }
        }
    }
    return to_string(M) + "\n" + ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}