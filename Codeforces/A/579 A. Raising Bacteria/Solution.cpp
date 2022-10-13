#include "iostream"
using namespace std;

int main() {
    int X, T = 0; cin >> X;
    while (X) {
        if (X % 2) {
            X--;
            T++;
        } else {
            X /= 2;
        }
    }
    cout << T << endl;
    return 0;
}