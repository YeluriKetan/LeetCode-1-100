#include <iostream>

using namespace std;

string solve() {
    int w;
    cin >> w;
    return (w > 3 && w % 2 == 0) ? "YES" : "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
