// 3548. Equal Sum Grid Partition II
// Daily Challenge - 26/03/2026

class Solution {
public:
    using ll = long long;

    bool checkPartition(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        ll upperSum = 0, lowerSum = 0;

        vector<int> upperFreq(100001, 0), lowerFreq(100001, 0);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                lowerSum += grid[i][j];
                lowerFreq[grid[i][j]]++;
            }
        }

        for (int i = 0; i < rows - 1; i++) {

            for (int j = 0; j < cols; j++) {
                int val = grid[i][j];

                lowerSum -= val;
                lowerFreq[val]--;

                upperSum += val;
                upperFreq[val]++;
            }

            if (upperSum == lowerSum) return true;

            ll diffUpper = upperSum - lowerSum;
            if (diffUpper > 0 && diffUpper <= 100000) {

                int h = i + 1, w = cols;

                if (h > 1 && w > 1) {
                    if (upperFreq[diffUpper]) return true;
                } 
                else if (h > 1 && w == 1) {
                    if (grid[0][0] == diffUpper || grid[i][0] == diffUpper)
                        return true;
                } 
                else if (h == 1 && w > 1) {
                    if (grid[0][0] == diffUpper || grid[0][w - 1] == diffUpper)
                        return true;
                }
            }

            ll diffLower = lowerSum - upperSum;
            if (diffLower > 0 && diffLower <= 100000) {

                int h = rows - i - 1, w = cols;

                if (h > 1 && w > 1) {
                    if (lowerFreq[diffLower]) return true;
                } 
                else if (h > 1 && w == 1) {
                    if (grid[i + 1][0] == diffLower || grid[rows - 1][0] == diffLower)
                        return true;
                } 
                else if (h == 1 && w > 1) {
                    if (grid[rows - 1][0] == diffLower || grid[rows - 1][w - 1] == diffLower)
                        return true;
                }
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (checkPartition(grid)) return true;

        int rows = grid.size(), cols = grid[0].size();

        vector<vector<int>> transposed(cols, vector<int>(rows));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed[j][i] = grid[i][j];
            }
        }

        return checkPartition(transposed);
    }
};