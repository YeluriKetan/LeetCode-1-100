#include "iostream"
#include "algorithm"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string a, b; cin >> a >> b;
    reverse(a.begin(), a.end());
    cout << (a == b ? "YES" : "NO") << "\n";
    return 0;
}