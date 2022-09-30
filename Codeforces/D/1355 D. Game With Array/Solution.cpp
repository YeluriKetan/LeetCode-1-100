#include "iostream"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, S; cin >> N >> S;
    if (S > 2 * N - 1) {
        cout << "YES\n";
        N--;
        while (N--) {
            cout << "1 ";
            S--;
        }
        cout << S << "\n" << S - 1 << "\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}