#include <iostream>
#include <unordered_set>

using namespace std;


int solve(unordered_set<int> palindromes) {
    int x, curr, total = 0;
    string s;
    unordered_set<int> reached;
    cin >> s >> x;
    curr = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
    while (reached.find(curr) == reached.end()) {
        if (palindromes.find(curr) != palindromes.end()) {
            total++;
        }
        reached.insert(curr);
        curr = (curr + x) % 1440;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    unordered_set<int> palindromes({0, 70, 140, 210, 280, 350, 601, 671, 741, 811, 881, 951, 1202, 1272, 1342, 1412});
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solve(palindromes) << "\n";
    }
    return 0;
}
