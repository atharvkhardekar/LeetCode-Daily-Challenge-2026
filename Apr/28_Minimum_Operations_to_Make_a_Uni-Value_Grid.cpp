// 2033. Minimum Operations to Make a Uni-Value Grid
// Daily Challenge - 28/04/2026

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        int remainder = arr[0] % x;
        for (int num : arr) {
            if (num % x != remainder) return -1;
        }

        sort(arr.begin(), arr.end());
        int median = arr[arr.size() / 2];

        int operations = 0;
        for (int num : arr) {
            operations += abs(num - median) / x;
        }

        return operations;
    }
};
