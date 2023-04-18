#include "iostream"
#include "cmath"
using namespace std;

double DR = acos(-1) / 180;

double solve() {
    int N; cin >> N;
    double A = ((2 * N - 2) * 180) / (double) (2 * N), P = 90, R = 1;
    N = (N - 2) / 2;
    while (N--) {
        P = A - 180 + P;
        R += 2 * cos(P * DR);
    }
    return R;
}

int main() {
    int T; cin >> T;
    while (T--) printf("%.9lf\n", solve());
    return 0;
}