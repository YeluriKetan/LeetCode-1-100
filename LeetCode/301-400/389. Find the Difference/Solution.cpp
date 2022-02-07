class Solution {
public:
    char findTheDifference(string s, string t) {
        char sArr[26] = {0};
        for (char curr: s) {
            sArr[curr - 'a']++;
        }
        for (char curr: t) {
            sArr[curr - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (sArr[i]) {
                return 'a' + i;
            }
        }
        return 0;
    }
};