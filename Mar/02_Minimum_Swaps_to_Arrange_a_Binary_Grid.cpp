// 1536. Minimum Swaps to Arrange a Binary Grid
// Daily Challenge - 02/03/2026

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros(n, 0);

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                count++;
            }
            trailingZeros[i] = count;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int required = n - i - 1;
            int j = i;

            while (j < n && trailingZeros[j] < required) {
                j++;
            }

            if (j == n) return -1;

            while (j > i) {
                swap(trailingZeros[j], trailingZeros[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};