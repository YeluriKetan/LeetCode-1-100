class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        unordered_map<char, string> charToString;
        unordered_map<string, char> stringToChar;
        stringstream stream(s);
        string currString;
        char currChar;
        int index = 0;
        while (index < n) {
            if (!(stream >> currString)) {
                return false;
            }
            currChar = pattern[index++];
            auto charMapPointer = charToString.find(currChar);
            if (charMapPointer == charToString.end()) {
                charToString.insert({currChar, currString});
            } else {
                if (charMapPointer->second != currString) {
                    return false;
                }
            }
            auto stringMapPointer = stringToChar.find(currString);
            if (stringMapPointer == stringToChar.end()) {
                stringToChar.insert({currString, currChar});
            } else {
                if (stringMapPointer->second != currChar) {
                    return false;
                }
            }
        }
        if (stream >> currString) {
            return false;
        }
        return true;
    }
};