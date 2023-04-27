#include "bits/stdc++.h"
using namespace std;

const regex AZ = regex("([A-Z]+)(\\d+)");
const regex RXCY = regex("R(\\d+)C(\\d+)");

string azToRxCy(string &s, smatch &matched) {
    int col = 0;
    for (auto c: matched[1].str()) {
        col *= 26;
        col += c - 'A' + 1;
    }
    return "R" + matched[2].str() + "C" + to_string(col);
}

string rxCyToAz(string &s, smatch &matched) {
    int row = stoi(matched[1].str());
    int col = stoi(matched[2].str());
    string cStr;
    while (col) {
        cStr += 'A' + (col + 25) % 26;
        col = (col - 1) /26;
    }
    reverse(cStr.begin(), cStr.end());
    return cStr + to_string(row);
}

string solve() {
    string s; cin >> s;
    smatch matched;
    if (regex_match(s, matched, AZ)) {
        return azToRxCy(s, matched);
    } else {
        regex_match(s, matched, RXCY);
        return rxCyToAz(s, matched);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}