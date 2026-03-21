// 3070. Count Submatrices with Top-Left Element and Sum Less Than k
// Daily Challenge - 18/03/2026

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        vector<vector<int>> pref(rows + 1, vector<int>(cols + 1, 0));
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                pref[i + 1][j + 1] = grid[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
                
                if (pref[i + 1][j + 1] <= k) {
                    count++;
                } else {
                    break;
                }
            }
        }
        
        return count;
    }
};