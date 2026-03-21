// 1727. Largest Submatrix With Rearrangements
// Daily Challenge - 17/03/2026

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        vector<vector<int>> height = matrix;

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (height[i][j])
                    height[i][j] += height[i-1][j];
            }
        }

        for (int i = 0; i < m; i++) {
            vector<int> row = height[i];
            sort(row.begin(), row.end(), greater<int>());

            for (int j = 0; j < n; j++) {
                ans = max(ans, row[j] * (j + 1));
            }
        }

        return ans;
    }
};
