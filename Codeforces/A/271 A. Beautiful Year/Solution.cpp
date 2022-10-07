#include "iostream"
#include "vector"
using namespace std;

bool isUnique(int n) {
    vector<bool> V(10, false);
    while (n) {
        if (V[n % 10]) return false;
        V[n % 10] = true;
        n /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int Y; cin >> Y;
    while (!isUnique(++Y)) { }
    cout << Y << "\n";
    return 0;
}