#include "iostream"
#include "vector"
#include "algorithm"
#include "tuple"
using namespace std;
typedef long long ll;
typedef tuple<int, int, ll> iil;

bool cmp(iil &a, iil &b) {
    if (get<0>(a) == get<0>(b)) {
        return get<1>(a) > get<1>(b);
    } else {
        return get<0>(a) < get<0>(b);
    }
}

iil fac23(ll X, ll Y) {
    int c2 = 0, c3 = 0;
    while (X % 2 == 0) {
        c2++;
        X /= 2;
    }
    while (X % 3 == 0) {
        c3++;
        X /= 3;
    }
    return make_tuple(c2, c3, Y);
}

int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;
    ll ai;
    vector<iil> V;
    while (N--) {
        cin >> ai;
        V.push_back(fac23(ai, ai));
    }
    sort(V.begin(), V.end(), cmp);
    for (auto &[c2, c3, X]: V) {
        cout << X << " ";
    }
    cout << endl;
    return 0;
}