#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    long long kmax, kmin, temp1, temp2;
    cin >> n >> m;
    temp1 = n / m + 1;
    kmin = (n % m) * ((temp1) * (temp1 - 1)) / 2;
    temp1 = n / m;
    kmin += (m - (n % m)) * ((temp1) * (temp1 - 1)) / 2;
    kmax = n - m + 1;
    kmax = (kmax * (n - m)) / 2;
    cout << kmin << " " << kmax << "\n";
    return 0;
}
