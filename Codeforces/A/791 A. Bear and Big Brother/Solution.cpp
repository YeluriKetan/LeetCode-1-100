#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int a, b, count = 0;
    cin >> a >> b;
    while (a <= b) {
        a *= 3;
        b *= 2;
        count++;
    }
    cout << count << "\n";
    return 0;
}
