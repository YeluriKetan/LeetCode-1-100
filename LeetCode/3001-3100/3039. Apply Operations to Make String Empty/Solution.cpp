#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> counts(26, 0);
        for (auto currChar: s) counts[currChar - 'a']++;
        int maxCount = max_element(counts.begin(), counts.end()).operator*();
        vector<bool> take(26, false);
        for (int i = 0; i < 26; ++i) if (counts[i] == maxCount) take[i] = true;
        string ans = "";
        for (int i = s.size() - 1; i > -1; i--) {
            if (take[s[i] - 'a']) {
                ans += s[i];
                take[s[i] - 'a'] = false;
            }
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};