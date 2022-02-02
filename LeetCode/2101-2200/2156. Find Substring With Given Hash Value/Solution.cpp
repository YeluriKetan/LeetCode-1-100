class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();
        long long currHash = 0;
        long long currPow = 1;
        int startInd = -1;
        for (int i = n - k; i < n - 1; ++i) {
            currHash += (s[i] - '`') * currPow;
            currHash %= modulo;
            currPow = (currPow * power) % modulo;
        }
        currHash += (s[n - 1] - '`') * currPow;
        currHash %= modulo;
        if (currHash == hashValue) {
            startInd = n - k;
        }
        for (int i = n - k - 1; i > -1; --i) {
            currHash += modulo;
            currHash -= ((s[i + k] - '`') * currPow) % modulo;
            currHash %= modulo;
            currHash = (currHash * power) % modulo;
            currHash += (s[i] - '`');
            currHash %= modulo;
            if (currHash == hashValue) {
                startInd = i;
            }
        }
        return s.substr(startInd, k);
    }
};