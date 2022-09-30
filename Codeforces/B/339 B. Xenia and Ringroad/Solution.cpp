#include "iostream"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, M, curr = 1, next; cin >> N >> M;
    long long ans = 0;
    while (M--) {
        cin >> next;
        ans += (next >= curr) ? next - curr : N - curr + next;
        curr = next;
    }
    cout << ans << "\n";
    return 0;
}