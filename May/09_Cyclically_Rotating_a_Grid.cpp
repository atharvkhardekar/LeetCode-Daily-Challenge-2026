// 1914. Cyclically Rotating a Grid
// Daily Challenge - 09/05/2026

class Solution {
public:
    
    void rotateLayer(vector<int>& layer, int k) {
        int len = layer.size();
        k %= len;

        reverse(layer.begin(), layer.end());
        reverse(layer.begin(), layer.begin() + (len - k));
        reverse(layer.begin() + (len - k), layer.end());
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            vector<int> elems;

            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            for (int j = left; j <= right; j++) {
                elems.push_back(grid[top][j]);
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                elems.push_back(grid[i][right]);
            }

            for (int j = right; j >= left; j--) {
                elems.push_back(grid[bottom][j]);
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                elems.push_back(grid[i][left]);
            }

            rotate(elems.begin(), elems.begin() + (k % elems.size()), elems.end());

            int idx = 0;

            for (int j = left; j <= right; j++) {
                grid[top][j] = elems[idx++];
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = elems[idx++];
            }

            for (int j = right; j >= left; j--) {
                grid[bottom][j] = elems[idx++];
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = elems[idx++];
            }
        }

        return grid;
    }
};
