// 1878. Get Biggest Three Rhombus Sums in a Grid
// Daily Challenge - 16/03/2026

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int, greater<int>> st;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                st.insert(grid[i][j]);

                for (int k = 1; i + 2*k < m && j - k >= 0 && j + k < n; k++) {

                    int sum = 0;

                    int x = i, y = j;

                    for (int t = 0; t < k; t++) {
                        sum += grid[x+t][y+t];
                    }

                    for (int t = 0; t < k; t++) {
                        sum += grid[x+k+t][y+k-t];
                    }

                    for (int t = 0; t < k; t++) {
                        sum += grid[x+2*k-t][y-t];
                    }

                    for (int t = 0; t < k; t++) {
                        sum += grid[x+k-t][y-k+t];
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (int x : st) {
            ans.push_back(x);
            if (ans.size() == 3) break;
        }

        return ans;
    }
};