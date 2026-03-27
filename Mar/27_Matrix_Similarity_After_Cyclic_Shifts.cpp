// 2946. Matrix Similarity After Cyclic Shifts
// Daily Challenge - 27/03/2026

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        k %= m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i % 2 == 0) {
                    int prevCol = (j - k + m) % m;
                    if (mat[i][j] != mat[i][prevCol])
                        return false;
                } 
                else {
                    int nextCol = (j + k) % m;
                    if (mat[i][j] != mat[i][nextCol])
                        return false;
                }
            }
        }

        return true;
    }
};