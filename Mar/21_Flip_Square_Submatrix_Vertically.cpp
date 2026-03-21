// 3643. Flip Square Submatrix Vertically
// Daily Challenge - 21/03/2026

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        for (int i = x; i < x + k / 2; i++) {
            int i2 = x + k - 1 - (i - x);  
            
            for (int j = y; j < y + k; j++) {
                swap(grid[i][j], grid[i2][j]);
            }
        }
        
        return grid;
    }
};