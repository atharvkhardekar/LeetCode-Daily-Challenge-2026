// 2906. Construct Product Matrix
// Daily Challenge - 24/03/2026

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int MOD = 12345;

        int size = m * n;
        vector<int> arr(size);

        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[idx++] = grid[i][j] % MOD;
            }
        }

        vector<int> prefix(size, 1), suffix(size, 1);

        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD;
        }

        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD;
        }

        vector<vector<int>> ans(m, vector<int>(n));
        idx = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = (prefix[idx] * suffix[idx]) % MOD;
                idx++;
            }
        }

        return ans;
    }
};