class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> tempMat(m, vector<int>(n));
        int temp;
        for (int i = 0; i < m; ++i) {
            temp = 0;
            for (int j = min(k - 1, n - 1); j > -1; --j) {
                temp += mat[i][j];
            }
            for (int j = 0; j < n; ++j) {
                if (j + k < n) {
                    temp += mat[i][j + k];
                }
                if (j - k > 0) {
                    temp -= mat[i][j - k - 1];
                }
                tempMat[i][j] += temp;
            }
        }
        for (int j = 0; j < n; ++j) {
            temp = 0;
            for (int i = min(k - 1, m - 1); i > -1; --i) {
                temp += tempMat[i][j];
            }
            for (int i = 0; i < m; ++i) {
                if (i + k < m) {
                    temp += tempMat[i + k][j];
                }
                if (i - k > 0) {
                    temp -= tempMat[i - k - 1][j];
                }
                mat[i][j] = temp;
            }
        }
        return mat;
    }
};