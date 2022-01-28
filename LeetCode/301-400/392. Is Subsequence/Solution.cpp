class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sizeT = t.size();
        int tPointer = 0;
        for (char currS: s) {
            while (tPointer < sizeT) {
                if (currS == t[tPointer]) {
                    break;
                } else {
                    tPointer++;
                }
            }
            if (tPointer == sizeT) {
                return false;
            } else {
                tPointer++;
            }
        }
        return true;
    }
};