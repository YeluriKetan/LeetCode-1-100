class Solution {
public:
    bool detectCapitalUse(string word) {
        int countCap = 0;
        for (char currChar: word) {
            if (currChar < 'a') {
                countCap++;
            }
        }
        if (countCap == word.size() || countCap == 0) {
            return true;
        } else if (countCap == 1 && word[0] < 'a') {
            return true;
        } else {
            return false;
        }
    }
};