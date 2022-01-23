class Solution {

    int powers[15] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};

    int numOfOnes(int i) {
        int count = 0;
        while (i > 0) {
            count += (i & 1);
            i >>= 1;
        }
        return count;
    }

    bool isValid(vector<vector<int>>& statements, int currAssum, int n) {
        for (int i = 0; i < n; ++i) {
            if ((currAssum & powers[i]) == 0) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (statements[i][j] == 2) {
                    continue;
                }
                if (statements[i][j] != ((currAssum & powers[j]) >> j)) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int currCount;
        int maxGood = 0;
        for (int i = (1 << n) - 1; i > 0; --i) {
            currCount = numOfOnes(i);
            if (currCount > maxGood && isValid(statements, i, n)) {
                maxGood = currCount;
            }
        }
        return maxGood;
    }
};
