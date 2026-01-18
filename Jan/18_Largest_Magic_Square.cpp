// 1895. Largest Magic Square
// Daily Challenge - 18/01/2026

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));
        vector<vector<int>> diag1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> diag2(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
            }
        }

        for (int size = min(m, n); size >= 2; size--) {
            for (int i = 0; i + size <= m; i++) {
                for (int j = 0; j + size <= n; j++) {

                    int target = row[i][j + size] - row[i][j];
                    bool ok = true;

                    for (int r = i; r < i + size && ok; r++) {
                        if (row[r][j + size] - row[r][j] != target)
                            ok = false;
                    }

                    for (int c = j; c < j + size && ok; c++) {
                        if (col[i + size][c] - col[i][c] != target)
                            ok = false;
                    }

                    if (diag1[i + size][j + size] - diag1[i][j] != target)
                        ok = false;

                    if (diag2[i + size][j] - diag2[i][j + size] != target)
                        ok = false;

                    if (ok) return size;
                }
            }
        }

        return 1; 
    }
};
