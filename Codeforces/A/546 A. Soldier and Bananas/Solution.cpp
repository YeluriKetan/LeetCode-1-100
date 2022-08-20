#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int k, n, w;
    cin >> k >> n >> w;
    cout << max(((w * (w + 1)) / 2) * k - n, 0) << "\n";
    return 0;
}
