#include <iostream>
#include <vector>

using namespace std;

long long solve() {
    int x, b, xi;
    cin >> x >> b;
    vector<pair<int, long long>> dishes(b + 1);
    long long yi;
    dishes[0] = {-1, 0};
    for (int i = 1; i <= b; ++i) {
        cin >> xi >> yi;
        dishes[i] = {xi, yi};
    }
    int c, pi;
    long long qi, ri;
    cin >> c;
    vector<pair<int, pair<long long, long long>>> clans(c);
    for (int i = 0; i < c; ++i) {
        cin >> pi >> qi >> ri;
        clans[i] = {pi, {qi, ri}};
    }
    int dishPointer = b, clanPointer = c - 1;
    while (clanPointer > -1 && clans[clanPointer].first > dishes[dishPointer].first) {
        clanPointer--;
    }
    long long currPeople = 0;
    bool flag = false;
    while (dishPointer > -1) {
        currPeople += dishes[dishPointer--].second;
        while (clanPointer > -1 && clans[clanPointer].first > dishes[dishPointer].first) {
            if (currPeople < clans[clanPointer].second.first) {
            } else if (currPeople < clans[clanPointer].second.first + clans[clanPointer].second.second) {
                currPeople = clans[clanPointer].second.first;
                flag = true;
            } else if (currPeople == clans[clanPointer].second.first + clans[clanPointer].second.second) {
                currPeople = clans[clanPointer].second.first;
            } else {
                currPeople -= clans[clanPointer].second.second;
            }
            clanPointer--;
        }
    }
    return (flag ? 0 : 1) + currPeople;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solve() << "\n";
    }
    return 0;
}
