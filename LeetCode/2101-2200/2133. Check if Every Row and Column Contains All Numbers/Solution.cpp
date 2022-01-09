class Solution {

public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        bool check[101] = {0};
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (check[matrix[i][j]] == flag) {
                    return false;
                } else {
                    check[matrix[i][j]] = flag;
                }
            }
            flag = !flag;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (check[matrix[j][i]] == flag) {
                    return false;
                } else {
                    check[matrix[j][i]] = flag;
                }
            }
            flag = !flag;
        }
        return true;
    }
};